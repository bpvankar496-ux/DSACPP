// 7.Next Greater Element using Stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreater(vector<int> arr) {
    stack<int> s;
    vector<int> ans(arr.size());

    for(int i = arr.size()-1; i >= 0; i--) {
        // remove smaller elements
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // if empty => no greater element
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();

        // push current
        s.push(arr[i]);
    }

    for(int x : ans) cout << x << " ";
}

int main() {
    vector<int> arr = {4, 5, 2, 10};
    nextGreater(arr);
}

//ANS:=
//5 10 10 -1 