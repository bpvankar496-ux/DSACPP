//Question 4: Trapping Rain Water (Complete Code)
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    stack<int> st;
    int water = 0;

    for (int i = 0; i < height.size(); i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();

            if (st.empty()) break;

            int distance = i - st.top() - 1;
            int bounded_height = min(height[i], height[st.top()]) - height[top];

            water += distance * bounded_height;
        }
        st.push(i);
    }

    return water;
}

int main() {
    vector<int> height = {7, 0, 4, 2, 5, 0, 6, 4, 0, 5};
    cout << trap(height);
    return 0;
}

//ANS:=
//25