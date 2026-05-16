//  Rod Cutting Problem
// Rod ne cut karine maximum profit banavo
#include <iostream>
#include <vector>
using namespace std;

int rodCutting(vector<int>& price, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int include = 0;
            if (i <= j) {
                include = price[i-1] + dp[i][j-i];
            }
            int exclude = dp[i-1][j];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[n][n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    cout << rodCutting(price, n) << endl;
    // 22
    return 0;
}

//ANS:=
//22