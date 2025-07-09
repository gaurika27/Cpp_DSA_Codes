A. Dijkstra's Algorithm is a greedy algorithm used to find the shortest path from a source node to all other nodes in a graph.

B. Where Dijkstra's Algorithm Works Perfectly
1) Graph Type:
  - ✅  Weighted graph (edges have weights/costs)
  - ✅  Undirected or directed graphs
  - ✅  Connected or disconnected graphs (but unreachable nodes will just remain ∞)

2) Edge Weights:
  - ✅  Non-negative edge weights only
  - ❌  NO negative edge weights allowed — Dijkstra will fail otherwise.

3) Structure:
  - Works on adjacency list or adjacency matrix
  - Can be used in:
  - Road networks
  - Flight connections
  - Network routing (e.g., shortest signal travel time)

C. ❌ Where Dijkstra Fails
 - Negative weights ❗
    Example: If an edge has weight -2, Dijkstra might mark a path as “final shortest” too early and miss the actual shortest one that uses the negative weight later.

 - For such cases, use Bellman-Ford Algorithm.
