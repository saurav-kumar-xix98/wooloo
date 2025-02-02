#include <library/LC2872_MaximumNumberOfKDivisibleComponents.hpp>
#include <datatype/Graph.hpp>

std::pair<int, int> dfs(const Datatype::Graph &graph, const std::vector<int> &values, std::vector<bool> &visiting, size_t node, int k) {
    const auto mod = [=](long long x) { return ((x % k) + k) % k; };
    int count = 0;
    long long sum = mod(values[node]);
    visiting[node] = true;
    for (const auto neighbor: graph.getNeighbors(node)) {
        if (visiting[neighbor])
            continue;
        auto [nCount, nSum] = dfs(graph, values, visiting, neighbor, k);
        count += nCount;

        if (nSum == 0)
            count++;
        else
            sum = mod(sum + nSum);
    }
    return {count, sum};
}

int LC2872::maxKDivisibleComponents(int n, std::vector<std::vector<int>> &edges, std::vector<int> &values, int k) {
    Datatype::Graph graph(n);
    for (const auto &edge: edges)
        graph.addEdge(edge[0], edge[1]);
    std::vector<bool> visiting(n);
    return dfs(graph, values, visiting, 0, k).first + 1;
}
