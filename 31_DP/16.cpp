//  Mountain Ranges
// N stones thi ketli alag alag mountain ranges banavi shakay — Catalan Number!
#include <iostream>
#include <vector>
using namespace std;

int mountainRanges(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i-1-j];
        }
    }
    return dp[n];
}

int main() {
    int n = 4;
    cout << mountainRanges(n) << endl;
    // 14
    return 0;
}

//ANS:=
//14