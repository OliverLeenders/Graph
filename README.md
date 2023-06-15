# Simple Adjacency-Set Graph Datastructure Implementation

## Motivation

Common Graph datastructures suffer from performance bottlenecks. For example in Adjacency Matrix datastructures the check whether there exists an edge between two vertices/nodes takes $\mathcal O(n)$ time and the addition adn removal of nodes is not really possible without moving whole the quadratic memory footprint of the matrix around.

On the other hand, Adjacency Lists do not make things much better as the removal of a node costs still $\mathcal O(n + m)$ time since we first need to find the node and remove all incident edges.

An Adjacency-Set-based datastructure can provide better modifability, since access times for edges and nodes are always constant. 

## Time Complexity
|Method | Time Complexity|
|-------|----------------|
|`add_node`|$\mathcal O(1)$|
|`add_edge`|$\mathcal O(1)$|
|`remove_node`|$\mathcal O(n)$|
|`remove_edge`|$\mathcal O(1)$|

## Implementation

This datastructure is relatively unoptimized for didactic purposes. The aim is to provide a clean, working implementation of an Adjacency-Set graph datastructure in the C++ language. The implementation uses `std::unordered_map` for the set of nodes, the set of edges and each node's neighbour relations.