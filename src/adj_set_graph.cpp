#include "adj_set_graph.h"

adj_set_graph::adj_set_graph() {
    nodes.reserve(10);
    edges.reserve(20);
}

adj_set_graph::~adj_set_graph() { 
    // nodes.clear(); 
}

void adj_set_graph::add_node() {
    uint32_t set_id = nodes.size();
    nodes[set_id] = node(set_id);
}

void adj_set_graph::add_node(uint32_t set_id) { nodes[set_id] = node(set_id); }

void adj_set_graph::remove_node(uint32_t id) {
    std::unordered_map<uint32_t, node>::iterator node_entry;
    if ((node_entry = nodes.find(id)) != nodes.end()) {
        node n = node_entry->second;
        for (auto e_entry : n.incident_edges) {
            nodes[e_entry.first].incident_edges.erase(n.id);
            edges.erase(edges[e_entry.second].id);
        }
        nodes.erase(id);
    }
}

void adj_set_graph::add_edge(uint32_t set_first, uint32_t set_second, float set_weight) {
    // declare iterators to first and second node
    std::unordered_map<uint32_t, node>::iterator first_node_entry;
    std::unordered_map<uint32_t, node>::iterator second_node_entry;
    // if both first and second node are present in the graph -> add edge between
    if ((first_node_entry = nodes.find(set_first)) != nodes.end() &&
        (second_node_entry = nodes.find(set_second)) != nodes.end()) {
        edge e = edge(edges.size(), set_first, set_second, set_weight);
        edges[e.id] = e;
        first_node_entry->second.incident_edges[set_second] = e.id;
        second_node_entry->second.incident_edges[set_first] = e.id;
    }
}

void adj_set_graph::print_graph() {
    for (auto n_entry : nodes) {
        node n = n_entry.second;
        std::cout << "NODE: " << n.id << std::endl;
        for (auto e_entry : n.incident_edges) {
            edge e = edges[e_entry.second];
            std::cout << "\tEDGE: #" << e.id << " (" << e.first << ", " << e.second << ")"
                      << std::endl;
        }
    }
}