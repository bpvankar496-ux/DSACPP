    // Question 7: Course Schedule III
// Maximum courses complete karo — Greedy + Priority Queue
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int scheduleCourse(vector<vector<int>>& courses) {
    // deadline thi sort karo
    sort(courses.begin(), courses.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });

    priority_queue<int> pq; // max heap — duration store karo
    int time = 0;

    for (auto course : courses) {
        int duration = course[0];
        int lastDay = course[1];

        if (time + duration <= lastDay) {
            time += duration;
            pq.push(duration);
        } else if (!pq.empty() && pq.top() > duration) {
            time -= pq.top();
            pq.pop();
            time += duration;
            pq.push(duration);
        }
    }
    return pq.size();
}

int main() {
    vector<vector<int>> courses = {{100,200},{200,1300},{1000,1250},{2000,3200}};
    cout << scheduleCourse(courses) << endl;
    // 3
    return 0;
}

//ANS:=
//3