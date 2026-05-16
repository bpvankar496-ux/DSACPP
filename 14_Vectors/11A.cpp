//ek number be vakht dublicate ch ane ek number missing ch e bnne sodho
#include <iostream>
#include <vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    vector<bool> isPresent(n+1, false);

    for(int i=0; i<n; i++) {
        if(isPresent[nums[i]]) {
            ans.push_back(nums[i]);
        }
        isPresent[nums[i]] = true;
    }

    for(int i=1; i<isPresent.size(); i++) {
        if(!isPresent[i]) {
            ans.push_back(i);
            break;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = findErrorNums(nums);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
//ANS:=
//[2, 3]

