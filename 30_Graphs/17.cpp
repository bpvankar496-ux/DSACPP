//  Kahn's Algorithm (Topological Sort - BFS/Indegree)
// Indegree use karine topo sort karo
#include <iostream>
#include <list>
#include <vector>
#include <queue>
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

    void kahnAlgo() {
        // indegree calculate karo
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int v : l[i]) {
                indegree[v]++;
            }
        }

        // indegree 0 wala nodes queue ma nakho
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int v : l[curr]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
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

    g.kahnAlgo();
    // 4 5 0 2 3 1
    return 0;
}

//ANS:=
//4 5 2 0 3 1 