#include <iostream>

#include "adj_set_graph.h"

int main() {
    adj_set_graph g = adj_set_graph();

    g.add_node(); // 0
    g.add_node(); // 1
    g.add_node(); // 2
    g.add_node(); // 3
    g.add_node(); // 4

    g.add_edge(0, 1, 0.5);
    g.add_edge(0, 2, 0.2);
    g.add_edge(0, 3, 0.4);
    g.add_edge(3, 2, 0.6);

    std::cout << "Graph has been created as follows: \n" << std::endl;

    g.print_graph();

    g.remove_node(0);


    std::cout << "\nRemoved Node 0 from the graph.\n" << std::endl;
    g.print_graph();
    return 0;
}