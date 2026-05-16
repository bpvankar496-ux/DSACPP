// User દ્વારા enter કરેલી String માં lowercase vowels (a, e, i, o, u) કેટલી વખત આવે છે તે count કરો.
#include <iostream>
#include <string>
using namespace std;

int getVowelCount(string str) {
    int vowCount = 0;

    for(int i=0; i<str.length(); i++) {
        if(str[i] == 'a' || str[i] == 'e' ||str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            vowCount++;
        }
    }

    return vowCount;
}

int main() {
    string str;
    cout << "String enter karo: ";
    cin >> str;
    cout << "Vowel count: " << getVowelCount(str) << "\n";
    return 0;
}

// ANS:=
// String enter karo: Ishaa
// Vowel count: 2