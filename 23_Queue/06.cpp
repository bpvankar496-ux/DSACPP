// Topic: First Non-Repeating Character in Stream

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string solve(string str) {
    queue<char> q;
    vector<int> freq(26, 0);
    string ans = "";

    for(char ch : str) {
        freq[ch - 'a']++;
        q.push(ch);

        // remove repeating chars
        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if(q.empty()) ans += '#';
        else ans += q.front();
    }

    return ans;
}

int main() {
    string str = "aabc";
    cout << solve(str);

    return 0;
}

//ANS:=
//a#bb