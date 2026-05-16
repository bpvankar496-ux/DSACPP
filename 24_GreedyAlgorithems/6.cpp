//india coins
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMinChange(vector<int> coins, int V) {
    int ans = 0;

    // sort coins (important for safety)
    sort(coins.begin(), coins.end());

    int n = coins.size();

    cout << "Coins used:\n";

    for(int i = n-1; i >= 0 && V > 0; i--) {
        if(V >= coins[i]) {
            int count = V / coins[i];

            cout << coins[i] << " x " << count << endl;

            ans += count;
            V = V % coins[i];
        }
    }

    cout << "min coins for change = " << ans << endl;

    return ans;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int V = 1099;

    getMinChange(coins, V);

    return 0;
}

// ANS:=
// Coins used:
// 500 x 2
// 50 x 1
// 20 x 2
// 5 x 1
// 2 x 2
// min coins for change = 8