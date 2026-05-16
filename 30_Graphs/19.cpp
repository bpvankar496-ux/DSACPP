//GRAPH PART 4
//  Dijkstra's Algorithm
// Weighted graph ma shortest path find karo — greedy approach
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    int V;
    list<pair<int,int>> *l; // {neighbor, weight}

public:
    Graph(int v) {
        V = v;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    void dijkstra(int src) {
        // {dist, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            for (auto neigh : l[curr]) {
                int v = neigh.first;
                int w = neigh.second;

                if (dist[curr] + w < dist[v]) {
                    dist[v] = dist[curr] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // print distances
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

    g.dijkstra(0);
    return 0;
}

// ANS:=
// dist[0] = 0
// dist[1] = 2
// dist[2] = 3
// dist[3] = 7
// dist[4] = 6