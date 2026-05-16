//connect N rope
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int connectNRopes(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());

    int cost = 0;

    while (pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();

        int min2 = pq.top();
        pq.pop();

        int sum = min1 + min2;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}

int main() {
    vector<int> ropes = {2, 3, 4, 6};

    int result = connectNRopes(ropes);
    cout << "Min cost = " << result << endl;

    return 0;
}

//ANS:=
///Min cost = 29