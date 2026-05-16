//first accurence
#include <iostream>
#include <vector>
using namespace std;

int firstOccur(vector<int> arr, int i, int target) {
    if(i == arr.size()) {
        return -1;
    }
    if(arr[i] == target) {
        return i;
    }
    return firstOccur(arr, i+1, target);
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4};
    cout << firstOccur(arr, 0, 3) << endl;
    return 0;
}

// i=0 → arr[0]=1 ≠ 3, next
// i=1 → arr[1]=2 ≠ 3, next
// i=2 → arr[2]=3 = 3  → return 2

//ANS:=
//2