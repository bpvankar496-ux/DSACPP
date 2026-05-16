// Question 5: Redundant Connection II
// Directed graph ma extra edge find karo
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent, rank_;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        rank_.resize(n+1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank_[px] < rank_[py]) parent[px] = py;
        else if (rank_[px] > rank_[py]) parent[py] = px;
        else { parent[py] = px; rank_[px]++; }
        return true;
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n+1, 0);
    vector<int> cand1, cand2;

    // double parent check
    for (auto edge : edges) {
        if (parent[edge[1]] == 0) {
            parent[edge[1]] = edge[0];
        } else {
            cand1 = {parent[edge[1]], edge[1]};
            cand2 = edge;
        }
    }

    DisjointSet ds(n);
    for (auto edge : edges) {
        if (edge == cand2) continue;
        if (!ds.unionSet(edge[0], edge[1])) {
            if (cand1.empty()) return edge;
            return cand1;
        }
    }
    return cand2;
}

int main() {
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> result = findRedundantDirectedConnection(edges);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

//ANS:=
//2 3