#include <iostream>

#include "adj_set_graph.h"

int main() {
    adj_set_graph g = adj_set_graph();

    g.add_node();
    g.add_node();
    g.add_edge(0, 1, 0.5);

    g.print_graph();

    return 0;
}