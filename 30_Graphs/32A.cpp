// Question 6: Couples Holding Hands
// Minimum swaps thi badha couples sathe beso — Greedy/Union Find
#include <iostream>
#include <vector>
using namespace std;

int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    int swaps = 0;

    for (int i = 0; i < n; i += 2) {
        int partner = row[i] % 2 == 0 ? row[i] + 1 : row[i] - 1;

        if (row[i+1] == partner) continue;

        // partner find karo ane swap karo
        for (int j = i+2; j < n; j++) {
            if (row[j] == partner) {
                swap(row[i+1], row[j]);
                swaps++;
                break;
            }
        }
    }
    return swaps;
}

int main() {
    vector<int> row = {0, 2, 1, 3};
    cout << minSwapsCouples(row) << endl;
    // 1
    return 0;
}

//ANS:=
//1