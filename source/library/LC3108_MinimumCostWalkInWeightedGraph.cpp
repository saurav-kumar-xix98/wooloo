#include <library/LC3108_MinimumCostWalkInWeightedGraph.hpp>
#include <queue>
#include <algorithm>
#include <datatype/Graph.hpp>

std::vector<int> LC3108::minimumCost(int n, std::vector<std::vector<int>> &edges, std::vector<std::vector<int>> &queries) {
    Datatype::WeightedMultiGraph graph(n);
    for (const auto& edge : edges)
        graph.addEdge(edge[0], edge[1], edge[2]);

    std::vector visited(n, false);
    std::vector<int> componentIds(n);
    std::vector<int> componentDist;
    std::queue<int> q;

    int currentId = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        q.push(i);
        componentDist.push_back(-1);
        while (!q.empty()) {
            const int node = q.front();
            q.pop();
            componentIds[node] = currentId;
            for (const auto& [neighbor, weight] : graph.getNeighbors(node)) {
                componentDist.back() &= weight;
                if (visited[neighbor])
                    continue;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        currentId++;
    }

    std::vector<int> result(queries.size());

    std::ranges::transform(queries, result.begin(), [&componentIds, &componentDist](const std::vector<int>& query) {
        if (componentIds[query[0]] != componentIds[query[1]])
            return -1;
        return componentDist[componentIds[query[0]]];
    });

    return result;
}
