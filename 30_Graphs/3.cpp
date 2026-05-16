//Adjacency Matrix
#include <iostream>
using namespace std;

int main() {

    int V = 4;

    int graph[4][4] = {0};

    // edges
    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;

    graph[2][3] = 1;
    graph[3][2] = 1;

    // print matrix
    for(int i=0; i<V; i++) {

        for(int j=0; j<V; j++) {

            cout << graph[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

// ANS:=
// 0 1 1 0 
// 1 0 0 1 
// 1 0 0 1 
// 0 1 1 0 