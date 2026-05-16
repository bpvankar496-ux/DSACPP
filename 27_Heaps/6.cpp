//k near by car
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Car class
class Car {
public:
    int idx;
    int distSq;

    Car(int i, int d) {
        idx = i;
        distSq = d;
    }

    //  Min Heap (smaller distance first)
    bool operator<(const Car &obj) const {
        return this->distSq > obj.distSq;
    }
};

// Function
void nearbyCars(vector<pair<int,int>> pos, int K) {
    priority_queue<Car> pq;

    // Step 1: push cars
    for (int i = 0; i < pos.size(); i++) {
        int x = pos[i].first;
        int y = pos[i].second;

        int distSq = x*x + y*y;

        pq.push(Car(i, distSq));
    }

    // Step 2: get K nearest
    for (int i = 0; i < K; i++) {
        cout << "Car " << pq.top().idx << endl;
        pq.pop();
    }
}

// Driver
int main() {
    vector<pair<int,int>> pos;

    pos.push_back({3, 3});
    pos.push_back({5, -1});
    pos.push_back({-2, 4});

    int K = 2;

    nearbyCars(pos, K);

    return 0;
}

//ANS:=
//Car 0
//Car 2