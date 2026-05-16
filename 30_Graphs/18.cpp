//  Kahn's Algorithm for Cycle Detection
// Kahn's algo thi directed graph ma cycle detect karo
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

    bool isCycle() {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int v : l[i]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // process thayela nodes count
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;

            for (int v : l[curr]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // je count < V hoy to cycle chhe
        return count != V;
    }
};

int main() {
    // No cycle
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    cout << (g1.isCycle() ? "Cycle exists" : "No cycle") << endl;
    // No cycle

    // Cycle
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);
    cout << (g2.isCycle() ? "Cycle exists" : "No cycle") << endl;
    // Cycle exists

    return 0;
}

//ANS:=
//No cycle
//Cycle exists