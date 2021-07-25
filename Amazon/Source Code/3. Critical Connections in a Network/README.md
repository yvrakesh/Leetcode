    Accepted        122,726
    Submissions     237,326
**Use case of this Question**:

    Bridges in a network can represent critical wires or connections which have to be prevented by adding connections or redesigning so as to increase its reliability (Since failure of those connections disconnects corresponding nodes from the network). 

***Naive Approach***:

    Time Complexity : O(E * (V + E))
    (DFS -> O(V + E) for all E edges)
    Space Complexity : O(1)
1. Find all the vertices which when removed increases number of components in the graph.
2. Remove an edge from the graph.
3. Perform DFS and see if there is only one component. If then its not a bridge. Else increment counter.
4. Put Back the edge.
5. Perform this for all the edges.


***Optimal Approach***: (Tarjon Algo)

    Time Complexity : O(V+E)
    Space Complexity : O(1)
1. Strongly Connected Components Identification.
2. DFS

**Condition for a bridge?**

    If there is no backedge from a subgraph to it's ancestor (across the bridge being checked) then the edge will be a BRIDGE.

1. We use dis(Node Discovery Time) and Low values (Lowest ID reachable) for nodes to find the back edge.

**Note** : Here we shouldn't include child to parent edge.

**Why?** Watch [here](https://www.youtube.com/watch?v=Rhxs4k6DyMM).

