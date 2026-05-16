//DFS Code
#include <iostream>
#include <vector>
using namespace std;

class Graph {

    int V;
    vector<int>* l;

public:

    Graph(int V) {

        this->V = V;

        l = new vector<int>[V];
    }

    void addEdge(int u, int v) {

        l[u].push_back(v);
        l[v].push_back(u);
    }

    void DFSHelper(int node,
                   vector<bool>& visited) {

        visited[node] = true;

        cout << node << " ";

        for(int nbr : l[node]) {

            if(!visited[nbr]) {

                DFSHelper(nbr, visited);
            }
        }
    }

    void DFS(int start) {

        vector<bool> visited(V, false);

        DFSHelper(start, visited);
    }
};

int main() {

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.DFS(0);

    return 0;
}

//ANS:=
//0 1 2 3 4 