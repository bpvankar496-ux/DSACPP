// Question 9: Number of Closed Islands
// Grid ma boundary thi surrounded islands count karo — DFS
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) return;

    grid[i][j] = 1; // visited mark karo

    dfs(grid, i-1, j);
    dfs(grid, i+1, j);
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);
}

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    // boundary thi connected 0s ne mark karo
    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 0) dfs(grid, i, 0);
        if (grid[i][n-1] == 0) dfs(grid, i, n-1);
    }
    for (int j = 0; j < n; j++) {
        if (grid[0][j] == 0) dfs(grid, 0, j);
        if (grid[m-1][j] == 0) dfs(grid, m-1, j);
    }

    // baaki islands count karo
    int count = 0;
    for (int i = 1; i < m-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (grid[i][j] == 0) {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid = {
        {1,1,1,1,1,1,1,0},
        {1,0,0,0,0,1,1,0},
        {1,0,1,0,1,1,1,0},
        {1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,0}
    };
    cout << closedIsland(grid) << endl;
    // 2
    return 0;
}

//ANS:=
//2