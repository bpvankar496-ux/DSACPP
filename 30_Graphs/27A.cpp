// Question 1: Redundant Connection
// Tree ma extra edge find karo — Disjoint Set use karo
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false; // cycle — e j redundant edge chhe
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else { parent[py] = px; rank[px]++; }
        return true;
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    DisjointSet ds(n);

    for (auto edge : edges) {
        if (!ds.unionSet(edge[0], edge[1])) {
            return edge;
        }
    }
    return {};
}

int main() {
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> result = findRedundantConnection(edges);
    cout << result[0] << " " << result[1] << endl;
    // 2 3
    return 0;
}

//ANS:=
//2 3