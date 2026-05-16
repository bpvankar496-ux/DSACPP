//  Bellman Ford Algorithm
// Negative weight edges pan handle kare — shortest path
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int v) { V = v; }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i < V-1; i++) {
            for (auto edge : edges) {
                if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.w;
                }
            }
        }

        for (auto edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.w < dist[edge.v]) {
                cout << "Negative cycle exists!" << endl;
                return;
            }
        }

        for (int i = 0; i < V; i++) {
            cout << "dist[" << i << "] = " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    g.bellmanFord(0);
    return 0;
}

// ANS:=
// dist[0] = 0
// dist[1] = 2
// dist[2] = 3
// dist[3] = 9
// dist[4] = 6