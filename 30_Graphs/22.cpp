//  Min Cost to Connect Points
// Badha points ne connect karva no minimum cost find karo — Prim's MST
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();
    vector<bool> inMST(n, false);
    vector<int> key(n, INT_MAX);
    key[0] = 0;

    // {cost, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});

    int totalCost = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (inMST[curr]) continue;
        inMST[curr] = true;
        totalCost += cost;

        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                // Manhattan distance
                int dist = abs(points[curr][0] - points[v][0]) +
                           abs(points[curr][1] - points[v][1]);

                if (dist < key[v]) {
                    key[v] = dist;
                    pq.push({dist, v});
                }
            }
        }
    }
    return totalCost;
}

int main() {
    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    cout << "Min Cost: " << minCostConnectPoints(points) << endl;
    // Min Cost: 20
    return 0;
}

//ANS:=
//Min Cost: 20