There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A **critical** connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

Example 1:

    Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
    Output: [[1,3]]
    Explanation: [[3,1]] is also accepted.
 

Constraints:

    2 <= n <= 105
    n - 1 <= connections.length <= 105
    0 <= ai, bi <= n - 1
    ai != bi
    There are no repeated connections.
    Accepted    122,726
    Submissions 237,326
**Use case of this Question**:

Bridges in a network can represent critical wires or connections which have to be prevented by adding connections or redesigning so as to increase its reliability (Since failure of those connections disconnects corresponding nodes from the network). 

***Naive Approach***:

1. Find all the vertices which when removed increases number of components in the graph.
2. Remove an edge from the graph.
3. Perform DFS and see if there is only one component. If then its not a bridge. Else increment counter.
4. Put Back the edge.
5. Perform this for all the edges.

Complexity : O(E * (V + E))

(DFS -> O(V + E) for all E edges)

***Optimal Approach***: (Tarjon Algo)

1. Strongly Connected Components Identification.
2. DFS

**Condition for a bridge?**

    If there is no backedge from a subgraph to it's ancestor (across the bridge being checked) then the edge will be a BRIDGE.

1. We use dis(Node Discovery Time) and Low values (Lowest ID reachable) for nodes to find the back edge.

**Note** : Here we shouldn't include child to parent edge.

**Why?** Watch [here](https://www.youtube.com/watch?v=Rhxs4k6DyMM).

