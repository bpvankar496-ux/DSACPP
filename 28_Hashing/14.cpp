//Count Subarrays with Sum = K Using prefix sum + hashmap
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarrayCountWithK(vector<int> arr, int K) {

    unordered_map<int, int> m; // <sum, count>

    m[0] = 1;

    int sum = 0;
    int ans = 0;

    for (int j = 0; j < arr.size(); j++) {

        sum += arr[j];

        // Check if (sum - K) exists
        if (m.count(sum - K)) {
            ans += m[sum - K];
        }

        // Store current prefix sum
        if (m.count(sum)) {
            m[sum]++;
        }
        else {
            m[sum] = 1;
        }
    }

    return ans;
}

int main() {

    vector<int> arr = {10, 2, -2, -20, 10};

    int K = -10;

    cout << "Count = "
         << subarrayCountWithK(arr, K)
         << endl;

    return 0;
}

//ANS:=
//Count = 3