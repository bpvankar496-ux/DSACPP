//eva 3 number sodho jeno sadvado 0 thy ...ema number koi bi ripit na thvo jooi e
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++) {
        if(i>0 && nums[i] == nums[i-1]) {
            continue;
        }

        int j = i+1;
        int k = n-1;

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            }
            else if(sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j<k && nums[j] == nums[j-1]) {
                    j++;
                }
                while(j<k && nums[k] == nums[k+1]) {
                    k--;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    for(auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    return 0;
}

// ANS:=
// [-1, -1, 2]
// [-1, 0, 1]