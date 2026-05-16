//બે strings s1 અને s2 આપેલી છે.
//નીચેની બે operations થી strings "close" બને:
//operation 1: બે characters ની position swap કરો
// Operation 2: બે characters ને એકબીજા સાથે બદલો
// At most આ operations વાપરીને બંને strings 
// equal બनावી શકાય તો true, નહીં તો false.
//INSHOT ANAGRAM VADA JEVO J QUE.
#include <iostream>
#include <string>
using namespace std;

bool closeStrings(string s1, string s2) {
    // Step 1: Length check
    if(s1.length() != s2.length()) {
        return false;
    }

    // Step 2: count array - drek letter ketliva vaar aave che
    int count1[26] = {0};
    int count2[26] = {0};

    for(int i=0; i<s1.length(); i++) {
        count1[s1[i]-'a']++;
    }
    for(int i=0; i<s2.length(); i++) {
        count2[s2[i]-'a']++;
    }

    // Step 3: Same letters exist kare che ke nahi?
    // (jya s1 ma 0 che tya s2 ma pan 0 hovu joiye)
    for(int i=0; i<26; i++) {
        if((count1[i]==0 && count2[i]!=0) ||
           (count1[i]!=0 && count2[i]==0)) {
            return false;
        }
    }

    // Step 4: Frequencies same che ke nahi?
    // (count sort karva badlye frequency match kariye)
    int freq1[26] = {0};
    int freq2[26] = {0};

    for(int i=0; i<26; i++) {
        freq1[count1[i]]++;
        freq2[count2[i]]++;
    }

    for(int i=0; i<26; i++) {
        if(freq1[i] != freq2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s1 = "abc";
    string s2 = "bca";
    cout << closeStrings(s1, s2) << "\n";   // 1 = true

    string s3 = "abc";
    string s4 = "bcd";
    cout << closeStrings(s3, s4) << "\n";   // 0 = false

    return 0;
}

//ANS:=
//1
//0