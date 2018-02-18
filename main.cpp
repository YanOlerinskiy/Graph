#include <iostream>

#include "graph.h"

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
    return 0;
}
