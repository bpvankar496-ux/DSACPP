//Question 1: Balanced String Split
#include <iostream>
using namespace std;

int balancedStringSplit(string s) {
    int countL = 0, countR = 0, ans = 0;

    for(char c : s) {
        if(c == 'L') countL++;
        else countR++;

        if(countL == countR) {
            ans++;
            countL = countR = 0;
        }
    }
    return ans;
}

int main() {
    string s = "RLRRLLRLRL";
    cout << "Output: " << balancedStringSplit(s) << endl;
    return 0;
}

//ANS:=
//Output: 4