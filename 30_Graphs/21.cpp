// Prim's Algorithm (MST)
// Minimum Spanning Tree — greedy thi minimum weight edges choose karo
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    int V;
    list<pair<int,int>> *l;

public:
    Graph(int v) {
        V = v;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    void prims() {
        // {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> inMST(V, false);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);

        key[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int curr = pq.top().second;
            pq.pop();

            inMST[curr] = true;

            for (auto neigh : l[curr]) {
                int v = neigh.first;
                int w = neigh.second;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = curr;
                    pq.push({key[v], v});
                }
            }
        }

        // MST print karo
        int totalCost = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
            totalCost += key[i];
        }
        cout << "Total MST cost: " << totalCost << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.prims();
    return 0;
}

// ANS:=
// 0 - 1 : 2
// 1 - 2 : 3
// 0 - 3 : 6
// 1 - 4 : 5
// Total MST cost: 16