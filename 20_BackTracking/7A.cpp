// Question 1: Rat in a Maze
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solveMazeUtil(int maze[][4], int x, int y, string sol, int N, vector<vector<bool>> vis) {
    if (x == N-1 && y == N-1 && maze[x][y] == 1) {
        cout << sol << "\n";
        return;
    }

    //up
    if(x-1 >= 0 && !vis[x-1][y] && maze[x-1][y] == 1) {
        vis[x][y] = true;
        solveMazeUtil(maze, x-1, y, sol+"U", N, vis);
        vis[x][y] = false;
    }
    //down
    if(x+1 < N && !vis[x+1][y] && maze[x+1][y] == 1) {
        vis[x][y] = true;
        solveMazeUtil(maze, x+1, y, sol+"D", N, vis);
        vis[x][y] = false;
    }
    //right
    if(y+1 < N && !vis[x][y+1] && maze[x][y+1] == 1) {
        vis[x][y] = true;
        solveMazeUtil(maze, x, y+1, sol+"R", N, vis);
        vis[x][y] = false;
    }
    //left
    if(y-1 >= 0 && !vis[x][y-1] && maze[x][y-1] == 1) {
        vis[x][y] = true;
        solveMazeUtil(maze, x, y-1, sol+"L", N, vis);
        vis[x][y] = false;
    }
}

void solveMaze(int maze[][4], int N) {
    string sol = "";
    vector<vector<bool>> vis(N, vector<bool>(N, false));

    if(maze[0][0] == 1) {
        solveMazeUtil(maze, 0, 0, sol, N, vis);
    }
}

int main(){
    int n = 4;
    int maze[4][4] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 1, 1, 0, 0 },
                       { 0, 1, 1, 1 } };
    solveMaze(maze, n);
}


// maze ma rat (0,0) thi start kare chhe
// (N-1, N-1) destination chhe
// 1 = ja shakay, 0 = blocked
// U/D/L/R = Up/Down/Left/Right
// Logic:

// Rat ek cell par jaay
// 4 directions try kare — U, D, R, L
// vis vector rakhe chhe — kai cell already visit karyu chhe te track kare
// Destination pahonche to path print karo
// Nahi pahonche to backtrack karo

//ANS:=
// DDRDRR
// DRDDRR