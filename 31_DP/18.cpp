//  Minimum Partitioning
// Array ne 2 parts ma divide karo jathi difference minimum hoy
#include <iostream>
#include <climits>  
#include <vector>
using namespace std;

int minPartition(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    for (int x : arr) sum += x;

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int minDiff = INT_MAX;
    for (int j = sum/2; j >= 0; j--) {
        if (dp[n][j]) {
            minDiff = sum - 2*j;
            break;
        }
    }
    return minDiff;
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    cout << minPartition(arr) << endl;
    // 1
    return 0;
}

//ANS:=
//1