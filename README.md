# Simple Adjacency-Set Graph Datastructure Implementation

## Motivation

Common Graph datastructures suffer from performance bottlenecks. For example in Adjacency Matrix datastructures the check whether there exists an edge between two vertices/nodes takes _O(n)_ time and the addition adn removal of nodes is not really possible without moving whole the quadratic memory footprint of the matrix around.

On the other hand, Adjacency Lists do not make things much better as the removal of a node costs still _O(n + m)_ time since we first need to find the node and remove all incident edges.

An Adjacency-Set-based datastructure can provide better modifability, since access times for edges and nodes are always constant. 

## Time Complexity

<table class="tg">
<thead>
  <tr>
    <th class="tg-0pky">Method</th>
    <th class="tg-0pky">Time Complexity</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-0pky">add_node</td>
    <td class="tg-0pky">O(1)</td>
  </tr>
  <tr>
    <td class="tg-0pky">add_edge</td>
    <td class="tg-0pky">O(1)</td>
  </tr>
  <tr>
    <td class="tg-0pky">remove_node</td>
    <td class="tg-0pky">O(n) [constant for sparse graphs]</td>
  </tr>
  <tr>
    <td class="tg-0lax">remove_edge</td>
    <td class="tg-0lax">O(1)</td>
  </tr>
</tbody>
</table>

## Implementation

This datastructure is relatively unoptimized for didactic purposes. The aim is to provide a clean, working implementation of an Adjacency-Set graph datastructure in the C++ language. The implementation uses `std::unordered_map` for the set of nodes, the set of edges and each node's neighbour relations.