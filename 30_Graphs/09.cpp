//  Cycle Detection Undirected
// Undirected graph ma cycle chhe ke nahi — parent check thi
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool undirCycleHelper(int src, int par, vector<bool> &vis) {
        vis[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors) {
            if (!vis[v]) {
                if (undirCycleHelper(v, src, vis)) {
                    return true;
                }
            } else {
                if (v != par) { //cycle condn
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); // cycle

    cout << (g.isCycleUndir() ? "Cycle exists" : "No cycle") << endl;
    return 0;
}

//ANS:=
//Cycle exists