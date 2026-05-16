//Adjacency List
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int V = 4;

    vector<int> graph[V];

    // edges
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    // print graph
    for(int i=0; i<V; i++) {

        cout << i << " -> ";

        for(int nbr : graph[i]) {

            cout << nbr << " ";
        }

        cout << endl;
    }

    return 0;
}

// ANS:=
// 0 -> 1 2 
// 1 -> 0 3 
// 2 -> 0 3 
// 3 -> 1 2 