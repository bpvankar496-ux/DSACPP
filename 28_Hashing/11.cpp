//intersection
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printIntersection(vector<int> arr1, vector<int> arr2) {

    unordered_set<int> s;

    // Insert arr1 into set
    for (int el : arr1) {
        s.insert(el);
    }

    // Check arr2
    for (int el : arr2) {

        if (s.find(el) != s.end()) {

            cout << el << " ";

            // remove to avoid duplicate printing
            s.erase(el);
        }
    }

    cout << endl;
}

int main() {

    vector<int> arr1 = {7, 3, 9};
    vector<int> arr2 = {6, 3, 9, 2, 9, 4};

    cout << "Intersection : ";
    printIntersection(arr1, arr2);

    return 0;
}

//ANS:=
//Intersection : 3 9 