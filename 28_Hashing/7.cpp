//Majority Element (> n/3 times)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void majorityElement(vector<int> nums) {

    // element -> frequency
    unordered_map<int, int> m;

    // Count frequency
    for (int i = 0; i < nums.size(); i++) {
        if (m.count(nums[i])) {
            m[nums[i]]++;
        }
        else {
            m[nums[i]] = 1;
        }
    }

    // Print majority elements
    cout << "Majority elements: ";

    for (pair<int,int> p : m) {
        if (p.second > nums.size() / 3) {
            cout << p.first << " ";
        }
    }

    cout << endl;
}

int main() {

    vector<int> nums = {1,2,3,1,1,2,1};

    majorityElement(nums);

    return 0;
}

//ANS:=
//Majority elements: 1 