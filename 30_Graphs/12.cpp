// All Paths Problem
// Source thi Destination sudhi badha possible paths print karo
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
        l[u].push_back(v); // directed
    }

    void pathHelper(int src, int dest, vector<bool> &vis, string &path) {
        if (src == dest) {
            cout << path << dest << endl;
            return;
        }

        vis[src] = true;
        path.push_back(src + '0');
        list<int> neighbors = l[src];

        for (int v : neighbors) {
            if (!vis[v]) {
                pathHelper(v, dest, vis, path);
            }
        }

        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }

    void printAllPaths(int src, int dest) {
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printAllPaths(0, 4);
    return 0;
}

//ANS:=
//0134
//0234