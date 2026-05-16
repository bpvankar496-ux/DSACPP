// Question 4: Generate Parentheses
// N pairs na valid parentheses generate karo
#include <iostream>
#include <vector>
using namespace std;

void generate(int open, int close, int n, string curr, vector<string>& result) {
    if (curr.size() == 2*n) {
        result.push_back(curr);
        return;
    }

    if (open < n) {
        generate(open+1, close, n, curr+"(", result);
    }
    if (close < open) {
        generate(open, close+1, n, curr+")", result);
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    generate(0, 0, n, "", result);
    return result;
}

int main() {
    vector<string> result = generateParentheses(3);
    for (auto s : result) {
        cout << s << endl;
    }
     return 0;
}

//ANS:=
// ((()))
// (()())
// (())()
// ()(())
// ()()()
   