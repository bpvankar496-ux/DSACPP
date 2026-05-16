//4. Reverse String using Stack==>Characters stack ma push kari ne reverse order ma pop kariye.
#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    string ans = "";

    for (char c : str) {
        s.push(c);
    }

    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main() {
    cout << reverseString("hello");
}

//ANS:=
//olleh