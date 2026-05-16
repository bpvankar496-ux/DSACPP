// GRAPH PART 1

// ## Introduction to Graphs

// Graph is a non-linear data structure consisting of:

// * Vertices (Nodes)
// * Edges (Connections)

// Example:

// A ----- B
// |       |
// |       |
// C ----- D


// Applications:

// * Google Maps
// * Social Networks
// * Computer Networks
// * Games

// # Types of Graphs

// ## 1. Undirected Graph

// Edges work in both directions.

// A ----- B


// Meaning:

// * A connected to B
// * B connected to A


// ## 2. Directed Graph

// Edges have direction.

// A -----> B

// Meaning:

// * A can go to B
// * B cannot go to A directly

// ## 3. Weighted Graph

// Edges contain weight/cost.

// A --5-- B

// Weight can represent:

// * distance
// * cost
// * time

// ## 4. Cyclic Graph

// Contains cycle.

// A → B → C → A


// ## 5. Acyclic Graph

// No cycle exists.

// # Graph using Adjacency List

// Most commonly used graph representation.

// vector<int> graph[V];

// Example:

// graph[0].push_back(1);
// graph[1].push_back(0);

// Meaning:

// * 0 connected to 1
// * 1 connected to 0

// Space Complexity:

// O(V + E)


// # Graph using Adjacency Matrix

// 2D matrix representation.

// int graph[4][4];

// Example:

// 0 1 0 1
// 1 0 1 0
// 0 1 0 1
// 1 0 1 0


// Space Complexity:

// O(V²)

// ---

// # Edge List

// Stores only edges.
// vector<pair<int,int>> edges;

// Example:

// edges.push_back({0,1});
// edges.push_back({1,2});



// # Implicit Graph

// Graph not stored directly.

// Neighbors generated dynamically.

// Examples:

// * Maze problems
// * Matrix traversal
// * Chess problems

// # Breadth First Search (BFS)

// Traverses graph level by level.

// Uses:

// * Queue
// * Visited Array

// Steps:

// 1. Push source node in queue
// 2. Mark visited
// 3. Pop node
// 4. Visit neighbors
// 5. Repeat

// Complexity:
// O(V + E)

// Applications:

// * Shortest path
// * Level traversal

// # Depth First Search (DFS)

// Traverses graph depth wise.

// Uses:

// * Recursion / Stack
// * Visited Array

// Steps:

// 1. Visit node
// 2. Mark visited
// 3. Visit neighbors recursively

// Complexity:
// O(V + E)


// Applications:

// * Cycle detection
// * Path finding
// * Connected components



// # BFS vs DFS

// | BFS           | DFS             |
// | ------------- | --------------- |
// | Queue         | Stack/Recursion |
// | Level Wise    | Depth Wise      |
// | Shortest Path | Backtracking    |
// | More Memory   | Less Memory     |



// # Important Terms

// | Term   | Meaning           |
// | ------ | ----------------- |
// | Vertex | Node              |
// | Edge   | Connection        |
// | Degree | Number of edges   |
// | Path   | Sequence of nodes |
// | Cycle  | Circular path     |



// # Important Complexities

// | Operation        | Complexity |
// | ---------------- | ---------- |
// | BFS              | O(V+E)     |
// | DFS              | O(V+E)     |
// | Adjacency Matrix | O(V²)      |
// | Adjacency List   | O(V+E)     |
