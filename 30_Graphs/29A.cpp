// Question 3: Max Area of Island
// Grid ma sabathi moto island find karo — DFS use karo
#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;

    grid[i][j] = 0; // visited mark karo

    return 1 + dfs(grid, i-1, j) + dfs(grid, i+1, j)
             + dfs(grid, i, j-1) + dfs(grid, i, j+1);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
    }
    return maxArea;
}

int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << maxAreaOfIsland(grid) << endl;
    // 6
    return 0;
}

//ANS:=
//6