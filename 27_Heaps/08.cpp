//weakest solider
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Row structure
struct Row {
    int soldiers;
    int idx;

    Row(int s, int i) {
        soldiers = s;
        idx = i;
    }

    // min heap based on soldiers, then index
    bool operator<(const Row &other) const {
        if (soldiers == other.soldiers)
            return idx > other.idx;
        return soldiers > other.soldiers;
    }
};

void weakestSoldier(vector<vector<int>> matrix, int K) {
    vector<Row> rows;

    // count soldiers in each row
    for (int i = 0; i < matrix.size(); i++) {
        int count = 0;
        for (int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++) {
            count++;
        }
        rows.push_back(Row(count, i));
    }

    // min heap
    priority_queue<Row> pq(rows.begin(), rows.end());

    // print K weakest rows
    for (int i = 0; i < K; i++) {
        cout << "Row " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };

    int K = 3;
    weakestSoldier(matrix, K);

    return 0;
}

// ANS:=
// Row 2
// Row 0
// Row 3