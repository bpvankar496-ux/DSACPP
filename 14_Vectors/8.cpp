//print index in sorted array for given number sum

//METHOD 1
#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> arr, int target){
    int st = 0;
    int end = arr.size()-1;
    vector<int> ans;
    while(st < end){
        int sum = arr[st] + arr[end];
        if(sum == target){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
        else if(sum > target){
            end--;
        }
        else{
            st++;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {2,7,11,15};
    int target = 9;
    vector<int> ans = pairSum(vec, target);
    cout<<ans[0]<<" , "<<ans[1];
    return 0;
}

//METHOD 2

#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v = {2,7,11,15};
    int target = 9;
    int st = 0;
    int end = v.size()-1;

    while(st < end){
        int sum = v[st] + v[end];
        if(sum == target){
            cout<<st<<" "<<end;
            break;
        }
        else if(sum > target){
            end--;
        }
        else{
            st++;
        }
    }
    return 0;
}

// ANS:=
// 0 , 1