//Building Graph using Adjacency List
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

    void print() {

        for(int i=0; i<V; i++) {

            cout << i << " -> ";

            for(int nbr : l[i]) {

                cout << nbr << " ";
            }

            cout << endl;
        }
    }
};

int main() {

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.print();

    return 0;
}

// ANS:=
// 0 -> 1 2 
// 1 -> 0 3 
// 2 -> 0 4 
// 3 -> 1 
// 4 -> 2 