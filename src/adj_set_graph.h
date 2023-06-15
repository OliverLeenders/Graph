#pragma once

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

class adj_set_graph {
  public:
    struct edge {
        // the id of the edge
        uint32_t id;
        // id of the first node
        uint32_t first;
        // id of the second node
        uint32_t second;
        float weight;

        /**
         * @brief Construct a new edge object
         *
         * @param set_id the new id
         * @param set_first the first node
         * @param set_second the second node
         * @param set_weight the weight of the edge
         */
        edge(uint32_t set_id, uint32_t set_first, uint32_t set_second, float set_weight) {
            this->id = set_id;
            this->first = set_first;
            this->second = set_second;
            this->weight = set_weight;
        }

        /**
         * @brief Construct a new edge object
         * Unsure why this is necessary...
         */
        edge() {
            this->id = 0U;
            this->first = 0U;
            this->second = 0U;
            this->weight = 0.0f;
        }
        ~edge() {}
    };

    /**
     * @brief Data structure for a node. Only contains an id and a map of neighboring nodes to the
     * corresponding incident edges.
     */
    struct node {
        // the node id
        uint32_t id;
        // the set of incident edge ids
        std::unordered_map<uint32_t, uint32_t> incident_edges =
            std::unordered_map<uint32_t, uint32_t>();
        node(uint32_t set_id) { this->id = set_id; }
        node() { this->id = 0U; }
        ~node() {}
    };
    std::unordered_map<uint32_t, node> nodes = std::unordered_map<uint32_t, node>();
    std::unordered_map<uint32_t, edge> edges = std::unordered_map<uint32_t, edge>();

    /**
     * @brief Adds a node to the graph. The node will be created inside this function. Its ID will
     * be the size of the graph before the insertion.
     */
    void add_node();

    /**
     * @brief Adds a node to the graph with a specific id to the graph. The node will be created
     * inside this function.
     *
     * @param set_id the id of the node to be created
     */
    void add_node(uint32_t set_id);

    /**
     * @brief Removes a node together with all its incident edges from the data-structure.
     *
     * @param id the id of the node to be removed
     */
    void remove_node(uint32_t id);

    /**
     * @brief Adds an edge between two EXISTING nodes in the graph with a given weight. If one or
     * both nodes specified do not exist in the graph, the edge will not be created.
     *
     * @param set_first
     * @param set_second
     * @param set_weight
     */
    void add_edge(uint32_t set_first, uint32_t set_second, float set_weight);

    /**
     * @brief Removes an edge by its ID.
     *
     * @param id the id of the edge to be removed
     */
    void remove_edge(uint32_t id);

    /**
     * @brief Prints a description / representation of the graph to the console.
     */
    void print_graph();

    /**
     * @brief Construct a new adj set graph object.
     */
    adj_set_graph();

    /**
     * @brief Destroy the adj set graph object.
     */
    ~adj_set_graph();
};
