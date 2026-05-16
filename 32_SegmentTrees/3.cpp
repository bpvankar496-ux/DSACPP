// Topic 3: Range Min Segment Tree + Update
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinSegTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = min(tree[2*node], tree[2*node+1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return INT_MAX;
        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        int left = query(2*node, start, mid, l, r);
        int right = query(2*node+1, mid+1, end, l, r);
        return min(left, right);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) update(2*node, start, mid, idx, val);
            else update(2*node+1, mid+1, end, idx, val);
            tree[node] = min(tree[2*node], tree[2*node+1]);
        }
    }

public:
    MinSegTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n, 0);
        build(arr, 1, 0, n-1);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    MinSegTree st(arr);

    cout << st.query(1, 4) << endl;  // min(3,5,7,9) = 3
    cout << st.query(0, 5) << endl;  // 1

    st.update(0, 15);
    cout << st.query(0, 3) << endl;  // min(15,3,5,7) = 3

    return 0;
}

//ANS:=
// 3
// 1
// 3