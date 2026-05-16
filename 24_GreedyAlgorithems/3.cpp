//fractional Knapsack
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort in descending order of ratio
bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first;
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int W) {
    int n = val.size();

    // pair<ratio, index>
    vector<pair<double, int>> ratio(n);

    // Compute value/weight ratio
    for (int i = 0; i < n; i++) {
        double r = (double)val[i] / wt[i];
        ratio[i] = make_pair(r, i);
    }

    // Sort by ratio descending
    sort(ratio.begin(), ratio.end(), compare);

    double ans = 0.0;

    for (int i = 0; i < n; i++) {
        int idx = ratio[i].second;

        if (wt[idx] <= W) {
            ans += val[idx];
            W -= wt[idx];
        } else {
            ans += ratio[i].first * W; // take fraction
            W = 0;
            break;
        }
    }

    return ans;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};
    int W = 50;

    double maxValue = fractionalKnapsack(val, wt, W);

    cout << "Maximum value = " << maxValue << endl;

    return 0;
}

//ANS:=
//Maximum value = 240