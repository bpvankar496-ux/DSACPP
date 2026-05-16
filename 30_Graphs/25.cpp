//  Kruskal's Algorithm (MST)
// Minimum Spanning Tree — edges ne sort karo, cycle na bane te rite add karo
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rnk;  

public:
    DisjointSet(int n) {
        parent.resize(n);
        rnk.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rnk[px] < rnk[py]) parent[px] = py;
        else if (rnk[px] > rnk[py]) parent[py] = px;
        else { parent[py] = px; rnk[px]++; }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

struct Edge {
    int w, u, v;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int v) { V = v; }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, u, v});
    }

    void kruskal() {
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int totalCost = 0;

        for (auto edge : edges) {
            if (!ds.isConnected(edge.u, edge.v)) {
                ds.unionSet(edge.u, edge.v);
                cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
                totalCost += edge.w;
            }
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

    g.kruskal();
    return 0;
}

//ANS:=
// 0 - 1 : 2
// 1 - 2 : 3
// 1 - 4 : 5
// 0 - 3 : 6
// Total MST cost: 16