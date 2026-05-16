// Question 10: Palindrome Partitioning
// String ne palindrome substrings ma partition karo — badha ways print karo
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

void solve(string& s, int start, vector<string>& curr, vector<vector<string>>& result) {
    if (start == s.size()) {
        result.push_back(curr);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            curr.push_back(s.substr(start, end-start+1));
            solve(s, end+1, curr, result);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> curr;
    solve(s, 0, curr, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);

    for (auto& part : result) {
        for (auto& p : part) cout << p << " ";
        cout << endl;
    }
    // a a b
    // aa b
    return 0;
}

//ANS:=
// a a b 
// aa b 