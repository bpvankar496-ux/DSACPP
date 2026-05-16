//print  all binary  possible pare
#include <iostream>
#include <string>
using namespace std;

// Method 1 - With lastPlace
void binString(int n, int lastPlace, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    if(lastPlace != 1) {
        binString(n-1, 0, ans + '0');
        binString(n-1, 1, ans + '1');
    } else {
        binString(n-1, 0, ans + '0');
    }
}

//Method 2 - Without lastPlace
void binString(int n, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    if(ans[ans.size()-1] != '1') {
        binString(n-1, ans + '0');
        binString(n-1, ans + '1');
    } else {
        binString(n-1, ans + '0');
    }
}

int main() {
    string ans = "";

    cout << "Method 1 (with lastPlace):" << endl;
    binString(3, 0, ans);

    cout << "\nMethod 2 (without lastPlace):" << endl;
    binString(3, ans);

    return 0;
}

// ANS:=
// Method 1 (with lastPlace):
// 000
// 001
// 010
// 100
// 101

// Method 2 (without lastPlace):
// 000
// 001
// 010
// 100
// 101