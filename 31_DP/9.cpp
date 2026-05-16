//  Longest Common Subsequence - Memoization + Tabulation
// 2 strings ma sabathi lamba common subsequence ni length
#include <iostream>
#include <vector>
using namespace std;

// Memoization
int lcsMemo(string& s1, string& s2, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0) return 0;
    if (dp[m][n] != -1) return dp[m][n];

    if (s1[m-1] == s2[n-1]) {
        dp[m][n] = 1 + lcsMemo(s1, s2, m-1, n-1, dp);
    } else {
        dp[m][n] = max(lcsMemo(s1, s2, m-1, n, dp),
                       lcsMemo(s1, s2, m, n-1, dp));
    }
    return dp[m][n];
}

// Tabulation
int lcsTab(string& s1, string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "ABCBDAB", s2 = "BDCAB";
    int m = s1.size(), n = s2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    cout << "Memoization: " << lcsMemo(s1, s2, m, n, dp) << endl;
    cout << "Tabulation: "  << lcsTab(s1, s2) << endl;
    // 4 (BCAB)
    return 0;
}

//ANS:=
//Memoization: 4
//Tabulation: 4