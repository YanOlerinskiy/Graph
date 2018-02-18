#include "graph.h"
#include <stdexcept>

Graph::Graph(int n_vertex)
    : n_vertex(n_vertex)
{

}

void Graph::addEdge(unsigned a, unsigned b)
{
    if (a >= n_vertex or b >= n_vertex) {
        throw std::invalid_argument("Ты дурак, ты ввел неправильный аргумент :-/");
    }
    edges.push_back(std::make_pair(a, b));
}

int Graph::vertexDegree(int v)
{
    int degree = 0;
    for (unsigned i = 0; i < edges.size(); i++) {
        if (edges[i].first == v or edges[i].second == v) {
            degree++;
        }
    }
    return degree;
}

void Graph::printMatrix()
{
    std::vector<int> matrix(n_vertex * n_vertex);
    for (unsigned i = 0; i < edges.size(); i++) {
        int v1 = edges[i].first;
        int v2 = edges[i].second;
        matrix[v2 * n_vertex + v1] = 1;
        matrix[v1 * n_vertex + v2] = 1;
    }
    for (int i = 0; i < n_vertex; i++) {
        for (int k = 0; k < n_vertex; k++) {
            std::cout << matrix[k * n_vertex + i] << " ";
        }
        std::cout << std::endl;
    }
}

bool Graph::checkComplete()
{

    std::vector<int> matrix(n_vertex*n_vertex);
    for (unsigned int i = 0; i < edges.size(); i++) {
        matrix[edges[i].first * n_vertex + edges[i].second] = 1;
        matrix[edges[i].second * n_vertex + edges[i].first] = 1;
    }
    bool isFull = 1;
    for (int i = 0; i < n_vertex; i++) {
        for (int k = 0; k < n_vertex; k++) {
            if (i == k) {
                continue;
            } else if (matrix[i * n_vertex + k] == 0){
                isFull = 0;
                break;
            }
         }
    }
    return isFull;
}

CompleteGraph::CompleteGraph(int n_vertex)
    : Graph(n_vertex)
{
    for (int i = 0; i < n_vertex; i++) {
        for(int k = i+1; k < n_vertex; k++) {
            addEdge(i, k);
        }
    }
}
