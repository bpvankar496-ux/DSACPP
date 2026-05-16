//10. Max Area in Histogram
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxArea(vector<int> h) {
    stack<int> s;
    int maxA = 0;
    int n = h.size();

    for(int i = 0; i <= n; i++) {
        while(!s.empty() && (i == n || h[s.top()] >= h[i])) {
            int height = h[s.top()];
            s.pop();

            int width;
            if(s.empty()) width = i;
            else width = i - s.top() - 1;

            maxA = max(maxA, height * width);
        }
        s.push(i);
    }

    return maxA;
}

int main() {
    vector<int> h = {2,1,5,6,2,3};
    cout << maxArea(h);
}

//ANS:=
//10