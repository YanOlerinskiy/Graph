#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <iostream>
class Graph
{
public:
    Graph(int n_vertex);

    void addEdge(unsigned a, unsigned b);

    int getNumVertices() { return n_vertex; }

    int getNumEdges() { return edges.size(); }

    int vertexDegree(int v);

    void printMatrix();

    bool checkComplete();

protected:
    int n_vertex;
    std::vector<std::pair<unsigned, unsigned>> edges;
};

class CompleteGraph : public Graph
{
public:
    CompleteGraph(int n_vertex);
};

#endif // GRAPH_H
