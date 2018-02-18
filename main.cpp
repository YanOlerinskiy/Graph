#include <iostream>

#include "graph.h"

Graph addGraphs(Graph &g1, Graph &g2)
{
    Graph g3(g1.getNumVertices() + g2.getNumVertices());
    g3.edges = g1.edges;
    for (int i = 0; i < g2.getNumVertices(); i++) {
        g3.addEdge(g2.edges[i].first + g1.getNumVertices(), g2.edges[i].second + g1.getNumVertices());
    }

    return g3;
}

int main()
{
    Graph g(5);
    try {
        g.addEdge(6, 2);
    } catch (std::exception &e) {
        std::cout << "Exception caught!" << std::endl;
        std::cout << e.what();
    }

    CompleteGraph k5(5);
    k5.printMatrix();
    std::cout << k5.checkComplete();
    g + k5;
    return 0;
}
