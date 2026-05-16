// Question: Array ni XOR Beauty sodho - jya badha possible triplets (i,j,k) mate (nums[i] | nums[j]) & nums[k] nu XOR return karvanu ch 
// Logic: badhu simplify thaine fakt (OR of all) & (XOR of all) bane ch
 #include <iostream>
#include <vector>
using namespace std;

int xorBeauty(vector<int>& nums) {
    int a = 0, b = 0;

    for(int i=0; i<nums.size(); i++) {
        a = a | nums[i];
        b = b ^ nums[i];
    }

    return ( a & b );
}

int main() {
    vector<int> nums = {1, 4};
    cout << xorBeauty(nums) << endl;
    return 0;
}
//ANS:=
//5