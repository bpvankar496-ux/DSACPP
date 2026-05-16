//9. Duplicate Parentheses using Stack
#include <iostream>
#include <stack>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s;

    for(char ch : str) {
        if(ch != ')') {
            s.push(ch);
        } else {
            // count inside brackets
            int count = 0;

            while(!s.empty() && s.top() != '(') {
                s.pop();
                count++;
            }

            s.pop(); // remove '('

            // if nothing inside => duplicate
            if(count == 0) return true;
        }
    }

    return false;
}

int main() {
    cout << isDuplicate("((a+b))") << endl; // 1
}

//ANS:=
//1