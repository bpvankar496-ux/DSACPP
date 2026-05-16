//DP PART 3

// Coin Change Problem
// Minimum coins thi target amount banavo
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;

    for (int j = 1; j <= amount; j++) {
        for (int coin : coins) {
            if (coin <= j && dp[j-coin] != INT_MAX) {
                dp[j] = min(dp[j], dp[j-coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 5, 6, 9};
    int amount = 11;
    cout << coinChange(coins, amount) << endl;
    // 2 (5+6)
    return 0;
}

//ANS:=
//2