//Q3: Task Scheduler
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char t : tasks) freq[t - 'A']++;

    priority_queue<int> pq;
    for (int f : freq) {
        if (f > 0) pq.push(f);
    }

    int time = 0;

    while (!pq.empty()) {
        int cycle = n + 1;
        vector<int> temp;

        while (cycle-- && !pq.empty()) {
            int f = pq.top(); pq.pop();
            if (f - 1 > 0) temp.push_back(f - 1);
            time++;
        }

        for (int x : temp) pq.push(x);

        if (pq.empty()) break;
        time += cycle + 1; // idle time
    }

    return time;
}

int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << leastInterval(tasks, n);
}

//8