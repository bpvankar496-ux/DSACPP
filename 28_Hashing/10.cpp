//union
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printUnion(vector<int> arr1, vector<int> arr2) {

    unordered_set<int> s;

    // Insert arr1
    for (int el : arr1) {
        s.insert(el);
    }

    // Insert arr2
    for (int el : arr2) {
        s.insert(el);
    }

    // Print union
    for (int el : s) {
        cout << el << " ";
    }

    cout << endl;
}

int main() {

    vector<int> arr1 = {7, 3, 9};
    vector<int> arr2 = {6, 3, 9, 2, 9, 4};

    cout << "Union : ";
    printUnion(arr1, arr2);

    return 0;
}

//ANS:=
//Union : 4 2 7 3 9 6 