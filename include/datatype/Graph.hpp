#pragma once

#include <vector>

namespace Datatype {
    class Graph {
    public:
        Graph(size_t N) : adjacencyList(N) {}
        void addEdge(size_t node1, size_t node2) {
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }
        const std::vector<size_t>& getNeighbors(size_t node) const {
            return adjacencyList[node];
        }
    private:
        std::vector<std::vector<size_t>> adjacencyList;
    };
}
