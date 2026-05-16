//Has Path Code
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

    bool hasPath(int src,
                 int dest,
                 vector<bool>& visited) {

        if(src == dest) {
            return true;
        }

        visited[src] = true;

        for(int nbr : l[src]) {

            if(!visited[nbr]) {

                if(hasPath(nbr,
                           dest,
                           visited)) {

                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    vector<bool> visited(5, false);

    cout << g.hasPath(0,4,visited);

    return 0;
}

//ANS:=
//1