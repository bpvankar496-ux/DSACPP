// Topic 11: Edit Distance
// Ek string ne biji string ma convert karva minimum operations
#include <iostream>
#include <vector>
using namespace std;

int editDistance(string& s1, string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                // min({}) ni jagya nested min use karo
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "horse", s2 = "ros";
    cout << editDistance(s1, s2) << endl;
    // 3
    return 0;
}

//ANS:=
//3