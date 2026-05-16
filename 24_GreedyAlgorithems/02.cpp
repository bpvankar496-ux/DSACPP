#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator (sort by end time)
bool compare(const pair<int, pair<int,int>> &a, const pair<int, pair<int,int>> &b) {
    return a.second.second < b.second.second;
}

int maxActivities(vector<pair<int, pair<int,int>>> &activity) {
    // Sort activities by end time
    sort(activity.begin(), activity.end(), compare);

    cout << "\n------ Sorted Activities (by end time) ------\n";
    for (int i = 0; i < activity.size(); i++) {
        cout << "A" << activity[i].first << " : "
             << activity[i].second.first << ", "
             << activity[i].second.second << endl;
    }

    // Select first activity
    cout << "\n------ Selected Activities ------\n";
    cout << "Selecting A" << activity[0].first << endl;

    int count = 1;
    int currentEndTime = activity[0].second.second;

    // Greedy selection
    for (int i = 1; i < activity.size(); i++) {
        if (activity[i].second.first >= currentEndTime) {
            cout << "Selecting A" << activity[i].first << endl;
            count++;
            currentEndTime = activity[i].second.second;
        }
    }

    return count;
}

int main() {
    vector<pair<int, pair<int,int>>> activity;

    // {id, {start, end}}
    activity.push_back({0, {0, 9}});
    activity.push_back({1, {1, 2}});
    activity.push_back({2, {2, 4}});
    activity.push_back({3, {5, 7}});
    activity.push_back({4, {8, 9}});

    cout << "------ Original Activities ------\n";
    for (int i = 0; i < activity.size(); i++) {
        cout << "A" << activity[i].first << " : "
             << activity[i].second.first << ", "
             << activity[i].second.second << endl;
    }

    int result = maxActivities(activity);

    cout << "\nMaximum number of activities: " << result << endl;

    return 0;
}

// ANS:=
// ------ Original Activities ------
// A0 : 0, 9
// A1 : 1, 2
// A2 : 2, 4
// A3 : 5, 7
// A4 : 8, 9

// ------ Sorted Activities (by end time) ------
// A1 : 1, 2
// A2 : 2, 4
// A3 : 5, 7
// A0 : 0, 9
// A4 : 8, 9

// ------ Selected Activities ------
// Selecting A1
// Selecting A2
// Selecting A3
// Selecting A4

// Maximum number of activities: 4