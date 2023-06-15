# Simple Adjacency-Set Graph Datastructure Implementation

## Motivation

Common Graph datastructures suffer from performance bottlenecks. For example in Adjacency Matrix datastructures the check whether there exists an edge between two vertices/nodes takes _O(n)_ time and the addition adn removal of nodes is not really possible without moving whole the quadratic memory footprint of the matrix around.

On the other hand, Adjacency Lists do not make things much better as the removal of a node costs still _O(n + m)_ time since we first need to find the node and remove all incident edges.

An Adjacency-Set-based datastructure can provide better modifability, since access times for edges and nodes are always constant. 

<style type="text/css">
.tg td{border-style:solid;
  overflow:hidden;padding:10px 5px;word-break:normal;}
</style>
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
    <td class="tg-0pky">O(n)</td>
  </tr>
  <tr>
    <td class="tg-0lax">remove_edge</td>
    <td class="tg-0lax">O(1)</td>
  </tr>
</tbody>
</table>