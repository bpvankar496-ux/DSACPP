//Largest Subarray with Sum = 0 using prefix sum + hashmap
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int largestSubWith0Sum(vector<int> arr) {

    unordered_map<int, int> m;

    int sum = 0;
    int ans = 0;

    for (int j = 0; j < arr.size(); j++) {

        sum += arr[j];

        // If prefix sum becomes 0
        if (sum == 0) {
            ans = j + 1;
        }

        // If same sum already exists
        if (m.count(sum)) {

            int currLen = j - m[sum];

            ans = max(ans, currLen);
        }
        else {
            m[sum] = j;
        }
    }

    return ans;
}

int main() {

    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};

    cout << "Largest subarray with sum 0 : "
         << largestSubWith0Sum(arr) << endl;

    return 0;
}

//ANS:=
//Largest subarray with sum 0 : 5