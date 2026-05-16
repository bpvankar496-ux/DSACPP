//Max chain length
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort by second value
bool compare(pair<int,int> p1, pair<int,int> p2) {
    return p1.second < p2.second;
}

int maxChainLength(vector<pair<int,int>> pairs) {
    int n = pairs.size();

    sort(pairs.begin(), pairs.end(), compare);

    vector<pair<int,int>> selected;

    // pick first pair
    selected.push_back(pairs[0]);
    int currEnd = pairs[0].second;

    for(int i = 1; i < n; i++) {
        if(pairs[i].first > currEnd) {
            selected.push_back(pairs[i]);
            currEnd = pairs[i].second;
        }
    }

    //  print selected pairs
    cout << "Selected pairs:\n";
    for(auto p : selected) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return selected.size();
}

int main() {
    vector<pair<int,int>> pairs;

    pairs.push_back({5, 24});
    pairs.push_back({39, 60});
    pairs.push_back({15, 28});
    pairs.push_back({27, 40});
    pairs.push_back({50, 90});

    int result = maxChainLength(pairs);

    cout << "Max chain length = " << result << endl;

    return 0;
}

// ANS:=
// Selected pairs:
// (5, 24)
// (27, 40)
// (50, 90)
// Max chain length = 3