#pragma once

#include <vector>
#include <unordered_set>

namespace Datatype {
    class Graph {
    public:
        Graph(const size_t N) : adjacencyList(N) {}
        void addEdge(const size_t node1, const size_t node2) {
            adjacencyList[node1].insert(node2);
            adjacencyList[node2].insert(node1);
        }
        const std::unordered_set<size_t>& getNeighbors(const size_t node) const {
            return adjacencyList[node];
        }
    private:
        std::vector<std::unordered_set<size_t>> adjacencyList;
    };

    class WeightedMultiGraph {
    public:
        explicit WeightedMultiGraph(const size_t N) : adjacencyList(N) {}
        void addEdge(const size_t node1, const size_t node2, const size_t weight) {
            adjacencyList[node1].push_back({node2, weight});
            adjacencyList[node2].push_back({node1, weight});
        }
        const std::vector<std::pair<size_t, size_t>>& getNeighbors(const size_t node) const {
            return adjacencyList[node];
        }
    private:
        std::vector<std::vector<std::pair<size_t, size_t>>> adjacencyList;
    };
}
