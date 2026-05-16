//GRAPH PART 3

//  Topological Sorting (DFS)
// Directed graph ma nodes ne linear order ma arrange karo
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
        l[u].push_back(v); // directed
    }

    void topoHelper(int src, vector<bool> &vis, stack<int> &st) {
        vis[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors) {
            if (!vis[v]) {
                topoHelper(v, vis, st);
            }
        }
        st.push(src); // badhа neighbors process thay pacchi push karo
    }

    void topoSort() {
        vector<bool> vis(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoHelper(i, vis, st);
            }
        }

        // print
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topoSort();
    // 5 4 2 3 1 0
    return 0;
}

//ANS:=
//5 4 2 3 1 0 