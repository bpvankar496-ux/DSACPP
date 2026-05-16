//DP PART 4

//  Longest Common Substring
// 2 strings ma sabathi lamba common substring ni length
#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubstring(string& s1, string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int maxLen = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return maxLen;
}

int main() {
    string s1 = "ABCBDAB", s2 = "BDCAB";
    cout << longestCommonSubstring(s1, s2) << endl;
    // 2 (AB)
    return 0;
}

//ANS:=
//2