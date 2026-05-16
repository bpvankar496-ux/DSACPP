//  Variation of Climbing Stairs
// K steps tak chadhavi shakay — minimum ways find karo
#include <iostream>
#include <vector>
using namespace std;

int climbK(int n, int k) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k && j <= i; j++) {
            dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

int main() {
    int n = 5, k = 3;
    cout << climbK(n, k) << endl;
    // 13
    return 0;
}

//ANS:=
//13