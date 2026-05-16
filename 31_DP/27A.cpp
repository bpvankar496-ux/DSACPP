// Question 9: Box Stacking
// Cuboids stack karo maximum height sathe
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxHeight(vector<vector<int>>& cuboids) {
    // drek cuboid sort karo
    for (auto& c : cuboids) sort(c.begin(), c.end());

    // cuboids ne sort karo
    sort(cuboids.begin(), cuboids.end());

    int n = cuboids.size();
    vector<int> dp(n);

    for (int i = 0; i < n; i++) dp[i] = cuboids[i][2];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (cuboids[j][0] <= cuboids[i][0] &&
                cuboids[j][1] <= cuboids[i][1] &&
                cuboids[j][2] <= cuboids[i][2]) {
                dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<vector<int>> cuboids = {{50,45,20},{95,37,53},{45,23,12}};
    cout << maxHeight(cuboids) << endl;
    // 190
    return 0;
}

//ANS:=
//190