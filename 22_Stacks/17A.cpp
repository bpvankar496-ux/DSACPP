//Question 3: Simplify Path (Complete Code)
#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    stack<string> st;
    string temp = "";

    for (int i = 0; i <= path.size(); i++) {
        if (i == path.size() || path[i] == '/') {
            if (temp == "..") {
                if (!st.empty()) st.pop();
            }
            else if (temp != "" && temp != ".") {
                st.push(temp);
            }
            temp = "";
        }
        else {
            temp += path[i];
        }
    }

    string res = "";
    while (!st.empty()) {
        res = "/" + st.top() + res;
        st.pop();
    }

    return res == "" ? "/" : res;
}

int main() {
    string path = "/home//foo/";
    cout << simplifyPath(path);
    return 0;
}

//ANS:=
///home/foo