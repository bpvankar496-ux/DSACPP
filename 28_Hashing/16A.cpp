//Question 2 : Two Sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {

    unordered_map<int,int> mp;

    for(int i=0; i<arr.size(); i++) {

        int complement = target - arr[i];

        if(mp.count(complement)) {
            return {mp[complement], i};
        }

        mp[arr[i]] = i;
    }

    return {};
}

int main() {

    vector<int> arr = {2,7,11,15};
    int target = 9;

    vector<int> ans = twoSum(arr, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}

//ANS:=
//0 1