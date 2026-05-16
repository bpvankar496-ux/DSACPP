// Question 1: Tribonacci Sequence
// T0=0, T1=1, T2=1, Tn+3 = Tn + Tn+1 + Tn+2
#include <iostream>
#include <vector>
using namespace std;

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main() {
    cout << tribonacci(4) << endl;  // 4
    cout << tribonacci(25) << endl; // 1389537
    return 0;
}

//ANS:=
// 4
// 1389537