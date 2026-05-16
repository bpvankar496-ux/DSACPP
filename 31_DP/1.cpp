// DP PART 1

//Fibonacci
// Nth Fibonacci number find karo — 3 approaches
#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Recursion — O(2^n)
// Har vaar same subproblem solve kare — slow!
int fibRec(int n) {
    // BC
    if (n == 0 || n == 1) return n;
    return fibRec(n-1) + fibRec(n-2);
}

// Approach 2: Memoization (Top Down) — O(n)
// Already solved subproblems dp ma store karo — fast!
int fibMemo(int n, vector<int>& dp) {
    // BC
    if (n == 0 || n == 1) return n;
    // already solve thayelu chhe to return karo
    if (dp[n] != -1) return dp[n];
    dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
    return dp[n];
}

// Approach 3: Tabulation (Bottom Up) — O(n)
// Nana subproblems thi sharu karo — iterative!
int fibTab(int n) {
    vector<int> dp(n+1);
    // BC
    dp[0] = 0;
    dp[1] = 1;
    // bottom up fill karo
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n = 10;

    // Recursion
    cout << "Recursion:   " << fibRec(n) << endl;

    // Memoization
    vector<int> dp(n+1, -1);
    cout << "Memoization: " << fibMemo(n, dp) << endl;

    // Tabulation
    cout << "Tabulation:  " << fibTab(n) << endl;
    // 55
    return 0;
}

// ANS:=
// Recursion:   55
// Memoization: 55
// Tabulation:  55