// Count BSTs from Nodes
// N nodes thi ketla alag alag BST banavi shakay — Catalan Number j chhe!
#include <iostream>
#include <vector>
using namespace std;

int countBSTs(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // j nodes left ma, i-1-j nodes right ma
            dp[i] += dp[j] * dp[i-1-j];
        }
    }
    return dp[n];
}

int main() {
    int n = 5;
    cout << countBSTs(n) << endl;
    // 42
    return 0;
}

//ANS:=
//42