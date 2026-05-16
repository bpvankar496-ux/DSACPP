//8. Valid Parentheses using Stack
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str) {
    stack<char> s;

    for(char ch : str) {
        // opening bracket
        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else {
            // if empty => invalid
            if(s.empty()) return false;

            char top = s.top();

            // check matching
            if((top == '(' && ch == ')') ||
               (top == '{' && ch == '}') ||
               (top == '[' && ch == ']')) {
                s.pop();
            } else {
                return false;
            }
        }
    }

    return s.empty(); // should be empty
}

int main() {
    cout << isValid("({})") << endl; // 1
}

//ANS:=
//1