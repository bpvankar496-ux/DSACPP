// Question 6: Longest Palindromic Subsequence
// String ma sabathi lamba palindromic subsequence ni length
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestPalindromicSubseq(string& s) {
    int n = s.size();
    // LPS = LCS of s and reverse of s
    string rev = s;
    reverse(rev.begin(), rev.end());

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == rev[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main() {
    string s = "bbbab";
    cout << longestPalindromicSubseq(s) << endl;
    // 4 (bbbb)
    return 0;
}

//ANS:=
//4