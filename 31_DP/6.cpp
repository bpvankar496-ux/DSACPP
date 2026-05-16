// Unbounded Knapsack
// Same item multiple times le shakay
#include <iostream>
#include <vector>
using namespace std;

int unboundedKnapsack(vector<int>& val, vector<int>& wt, int n, int W) {
    vector<int> dp(W+1, 0);

    for (int j = 1; j <= W; j++) {
        for (int i = 0; i < n; i++) {
            if (wt[i] <= j) {
                dp[j] = max(dp[j], val[i] + dp[j-wt[i]]);
            }
        }
    }
    return dp[W];
}

int main() {
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt  = {1, 3, 4, 5};
    int W = 8, n = val.size();

    cout << unboundedKnapsack(val, wt, n, W) << endl;
    // 110
    return 0;
}

//ANS:=
//110