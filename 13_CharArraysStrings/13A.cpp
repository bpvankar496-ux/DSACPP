//String ma brackets આપેલા છે: ( ) { } [ ]
// Valid છે કે નહીં તે check કરો.
// Input:  s = "()"      → Output: true
// Input:  s = "()[]{}"  → Output: true  
// Input:  s = "(]"      → Output: false

#include <iostream>
#include <string>
using namespace std;

bool isValid(string s) {
    char arr[10000];
    int top = -1;

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];

        if(ch=='(' || ch=='{' || ch=='[') {
            top++;
            arr[top] = ch;
        }
        else {
            if(top == -1) return false;

            if(ch==')' && arr[top]=='(') top--;
            else if(ch=='}' && arr[top]=='{') top--;
            else if(ch==']' && arr[top]=='[') top--;
            else return false;
        }
    }

    return top == -1;
}

int main() {
    cout << isValid("()") << "\n";      // 1 = true
    cout << isValid("()[]{}") << "\n";  // 1 = true
    cout << isValid("(]") << "\n";      // 0 = false
    return 0;
}

//ANS:=
//1
//1
//0