#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

// sort by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int maxProfit(vector<pair<int,int>> pairs) {
    int n = pairs.size();

    // convert to Job objects (same as your code)
    vector<Job> jobs;
    for(int i = 0; i < n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    // sort
    sort(jobs.begin(), jobs.end(), compare);

    // find max deadline
    int maxDeadline = 0;
    for(auto j : jobs) {
        maxDeadline = max(maxDeadline, j.deadline);
    }

    // slot array
    vector<int> slot(maxDeadline + 1, -1);

    int profit = 0;

    cout << "Selecting jobs:\n";

    // greedy scheduling
    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;

                cout << "Job" << jobs[i].idx << endl;

                profit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "max profit = " << profit << endl;

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

 //ANS:=
// Selecting jobs:
// Job2
// Job0
// max profit = 60