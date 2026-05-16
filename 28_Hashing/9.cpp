//counts distinct(unique) elements using unordered_set 
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countDistinct(vector<int> arr) {

    unordered_set<int> s;

    // Insert all elements
    for (int i = 0; i < arr.size(); i++) {
        s.insert(arr[i]);
    }

    // Print unique elements
    for (int el : s) {
        cout << el << " ";
    }

    cout << endl;

    // Number of distinct elements
    return s.size();
}

int main() {

    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};

    cout << "count = " << countDistinct(arr) << endl;

    return 0;
}

//ANS:=
//1 7 6 4 3 2 5 
//count = 7