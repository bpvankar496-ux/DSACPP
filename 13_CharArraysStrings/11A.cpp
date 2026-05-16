// બે equal length ની strings s1 અને s2 આપેલી છે. 
// એક string માં at most એક swap કરીને 
// બંને strings equal થઈ શકે તો true, 
// નહીં તો false return કરો.

// Example:
// Input:  s1 = "bank", s2 = "kanb"
//Output: true

//METHOD 1

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "bank";
    string s2 = "kanb";
    int first = -1;
    int second = -1;

    for(int i=0; i<s1.size(); i++) {
        if(s1[i] != s2[i]) {
            if(first == -1) {
                first = i;
            }
            else if(second == -1) {
                second = i;
            }
            else {
                cout << "false";
                return 0;
            }
        }
    }
    if(first == -1) {
        cout << "true";
    }
    else if(second == -1) {
        cout << "false";
    }
    else if(s1[first] == s2[second] &&
            s1[second] == s2[first]) {

        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}

//METHOD 2
#include <iostream>
#include <string>
using namespace std;

bool areAlmostEqual(string s1, string s2) {
    if(s1.length() != s2.length()) {
        return false;
    }

    char diffChar1, diffChar2;
    int diff = 0;

    for(int i=0; i<s1.length(); i++) {
        if(s1[i] != s2[i]) {
            if(!diff) {
                diffChar1 = s1[i];
                diffChar2 = s2[i];
            } else {
                if(s1[i] != diffChar2 || s2[i] != diffChar1) {
                    return false;
                }
            }
            diff++;
        }
    }

    if(diff > 2) {
        return false;
    }

    return true;
}

int main() {
    string s1 = "bank";
    string s2 = "kanb";

    if(areAlmostEqual(s1, s2)) {
        cout << "Output: true\n";
    } else {
        cout << "Output: false\n";
    }

    return 0;
}

//ANS:=
//Output: true