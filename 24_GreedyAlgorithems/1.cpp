//activity selction
#include <iostream>
#include <vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end) {
    // sort on end time (NOTE: assumes already sorted for simplicity)

    // A0 select
    cout << "selecting A0\n";
    int count = 1;
    int currentEndTime = end[0];

    for (int i = 1; i < start.size(); i++) {
        if (start[i] >= currentEndTime) { // non-overlapping
            cout << "selecting A" << i << endl;
            count++;
            currentEndTime = end[i];
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    int result = maxActivities(start, end);
    cout << "Maximum number of activities: " << result << endl;

    return 0;
}

//ANS:=
//selecting A0
// selecting A1
// selecting A3
// selecting A4
// Maximum number of activities: 4