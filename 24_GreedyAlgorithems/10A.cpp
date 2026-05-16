//Question 2: Largest Odd Number in String
#include <iostream>
using namespace std;

string largestOddNumber(string num) {
    for(int i = num.length() - 1; i >= 0; i--) {
        if((num[i] - '0') % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main() {
    string num = "52";
    cout << "Output: " << largestOddNumber(num) << endl;
    return 0;
}

//ANS:=
//Output: 5