//Priority Queue for Pair
#include <iostream>
#include <queue>
using namespace std;

struct ComparePair {
    bool operator()(pair<string,int> &p1, pair<string,int> &p2) {
        return p1.second < p2.second; // max heap
    }
};

int main() {
    priority_queue<
        pair<string,int>,
        vector<pair<string,int>>,
        ComparePair
    > pq;

    pq.push({"Harsh", 500});
    pq.push({"Bhoomika", 1000});
    pq.push({"Vivek", 100});

    while(!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}

// ANS:=
// Bhoomika 1000
// Harsh 500
// Vivek 100