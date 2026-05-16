//  Disjoint Set (Union Find)
// 2 nodes same set ma chhe ke nahi check karo
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        // union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    DisjointSet ds(5);
    ds.unionSet(0, 1);
    ds.unionSet(1, 2);
    ds.unionSet(3, 4);

    cout << ds.isConnected(0, 2) << endl; // 1 (true)
    cout << ds.isConnected(0, 3) << endl; // 0 (false)
    return 0;
}

//ANS:=
//1
//0