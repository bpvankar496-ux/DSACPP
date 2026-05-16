//  Course Schedule II
// Courses ni order print karo — Topological Sort
#include <iostream>
#include <list>
#include <vector>
#include <stack>
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
                if (dirCycleHelper(v, vis, recPath)) return true;
            } else {
                if (recPath[v]) return true;
            }
        }
        recPath[src] = false;
        return false;
    }

    void topoHelper(int src, vector<bool> &vis, stack<int> &st) {
        vis[src] = true;
        for (int v : l[src]) {
            if (!vis[v]) {
                topoHelper(v, vis, st);
            }
        }
        st.push(src);
    }

    void courseSchedule2() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        // pehla cycle check karo
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dirCycleHelper(i, vis, recPath)) {
                    cout << "No valid order exists" << endl;
                    return;
                }
            }
        }

        // topo sort
        fill(vis.begin(), vis.end(), false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoHelper(i, vis, st);
            }
        }

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(1, 0);
    g.addEdge(2, 0);
    g.addEdge(3, 1);
    g.addEdge(3, 2);

    g.courseSchedule2();
    // 3 2 1 0
    return 0;
}
//ANS:=
//3 2 1 0 