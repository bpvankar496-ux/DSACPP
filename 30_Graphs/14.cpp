//  Course Schedule I
// Courses complete kari shakay ke nahi — cycle chhe ke nahi check karo
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
    }

    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath) {
        vis[src] = true;
        recPath[src] = true;

        for (int v : l[src]) {
            if (!vis[v]) {
                if (dirCycleHelper(v, vis, recPath)) {
                    return true;
                }
            } else {
                if (recPath[v]) {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool canFinish() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dirCycleHelper(i, vis, recPath)) {
                    return false; // cycle chhe — complete na thay
                }
            }
        }
        return true; // no cycle — complete thay
    }
};

int main() {
    // 2 courses, 1 prerequisite: 0->1
    Graph g(2);
    g.addEdge(0, 1);

    cout << (g.canFinish() ? "Can finish" : "Cannot finish") << endl;
    // Can finish

    // Cycle case
    Graph g2(2);
    g2.addEdge(0, 1);
    g2.addEdge(1, 0);

    cout << (g2.canFinish() ? "Can finish" : "Cannot finish") << endl;
    // Cannot finish
    return 0;
}

//ANS:=
//Can finish
//Cannot finish