//GRAPH PART 2

// BFS + Disconnected Components
// BFS thi graph traverse karo, disconnected nodes pan cover thay
#include <iostream>
#include <list>
#include <queue>
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

    void bfsHelper(int st, vector<bool> &vis) {
        queue<int> q;
        q.push(st);
        vis[st] = true;

        while (q.size() > 0) {
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            list<int> neighbors = l[curr];
            for (int neigh : neighbors) {
                if (!vis[neigh]) {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout << endl;
    }

    void bfs() {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bfsHelper(i, vis);
            }
        }
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(5, 6); // disconnected component

    g.bfs();
    return 0;
}

//ANS:=
// 0 1 2 3 4 
//5 6 