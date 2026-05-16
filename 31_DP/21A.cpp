// Question 3: Longest Increasing Path in Matrix
// Matrix ma sabathi lamba increasing path find karo — DFS + Memo
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
    if (dp[i][j] != 0) return dp[i][j];

    int m = matrix.size(), n = matrix[0].size();
    int maxLen = 1;

    for (int d = 0; d < 4; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
            matrix[ni][nj] > matrix[i][j]) {
            maxLen = max(maxLen, 1 + dfs(matrix, dp, ni, nj));
        }
    }
    dp[i][j] = maxLen;
    return maxLen;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int result = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, dfs(matrix, dp, i, j));
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    cout << longestIncreasingPath(matrix) << endl;
    // 4 (1->2->6->9)
    return 0;
}

//ANS:=
//4