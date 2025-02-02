#include <library/LC2440_CreateComponentsWithSameValue.hpp>
#include <datatype/Graph.hpp>

namespace LC2440 {
    int canSplitIntoComponents(const Datatype::Graph &graph, const std::vector<int> &values, std::vector<bool> &visiting, const int node, const int target) {
        visiting[node] = true;

        int sum = values[node];
        if (sum > target)
            return -1;

        for (const auto &neighbor: graph.getNeighbors(node)) {
            if (visiting[neighbor])
                continue;
            int val = canSplitIntoComponents(graph, values, visiting, neighbor, target);
            if (val == -1)
                return -1;
            sum += val;
        }

        if (sum > target)
            return -1;

        if (sum == target)
            return 0;

        return sum;
    }
}

int LC2440::componentValue(std::vector<int> &values, std::vector<std::vector<int>> &edges) {
    Datatype::Graph graph(values.size());
    for (const auto &edge: edges)
        graph.addEdge(edge[0], edge[1]);

    int sum = 0;
    for (const auto num: values)
        sum += num;

    for (int i = 1; i <= sum; ++i) {
        if (sum % i != 0)
            continue;
        std::vector<bool> visiting(values.size());
        if (canSplitIntoComponents(graph, values, visiting, 0, i) == 0) {
            return sum / i - 1;
        }
    }

    return -1;
}
