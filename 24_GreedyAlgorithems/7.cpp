//max profit from jobs
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sort by profit (descending)
bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}

int maxProfit(vector<pair<int,int>> jobs) {
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), compare);

    // find max deadline
    int maxDeadline = 0;
    for(auto job : jobs) {
        maxDeadline = max(maxDeadline, job.first);
    }

    // Slot array (initially empty)
    vector<int> slot(maxDeadline + 1, -1);

    int profit = 0;

    cout << "Selected jobs:\n";

    for(int i = 0; i < n; i++) {
        int deadline = jobs[i].first;

        // try to fit in latest possible slot
        for(int j = deadline; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                profit += jobs[i].second;

                cout << "Job (d=" << jobs[i].first 
                     << ", p=" << jobs[i].second << ")\n";
                break;
            }
        }
    }

    cout << "max profit from jobs : " << profit << endl;

    return profit;
}

int main() {
    vector<pair<int,int>> jobs;

    // {deadline, profit}
    jobs.push_back({4, 20});
    jobs.push_back({1, 10});
    jobs.push_back({1, 40});
    jobs.push_back({1, 30});

    maxProfit(jobs);

    return 0;
}

// ANS:=
// Selected jobs:
// Job (d=1, p=40)
// Job (d=4, p=20)
// max profit from jobs : 60