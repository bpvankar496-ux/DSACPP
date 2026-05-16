//Question 3: Smallest String With Given Value
#include <iostream>
using namespace std;

string getSmallestString(int n, int k) {
    string ans = "";

    while(n > 0) {
        int val = k - (n - 1) * 26;

        if(val <= 0) {
            ans.push_back('a');
            k -= 1;
        } else {
            ans.push_back('a' + val - 1);
            k -= val;
        }
        n--;
    }

    return ans;
}

int main() {
    int n = 3, k = 27;
    cout << "Output: " << getSmallestString(n, k) << endl;
    return 0;
}

//ANS:=
//Output: aay