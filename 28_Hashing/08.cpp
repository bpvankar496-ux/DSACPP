//Valid anagram
#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {

    // Length check
    if (s.size() != t.size()) {
        return false;
    }

    // <char, freq>
    unordered_map<char, int> freq;

    // Count chars of s
    for (int i = 0; i < s.size(); i++) {

        if (freq.count(s[i])) {
            freq[s[i]]++;
        }
        else {
            freq[s[i]] = 1;
        }
    }

    // Match chars from t
    for (int i = 0; i < t.size(); i++) {

        if (freq.count(t[i])) {

            freq[t[i]]--;

            if (freq[t[i]] == 0) {
                freq.erase(t[i]);
            }
        }
        else {
            return false;
        }
    }

    return freq.empty();
}

int main() {

    string s = "listen";
    string t = "silent";

    if (isAnagram(s, t)) {
        cout << "Valid Anagram";
    }
    else {
        cout << "Not Anagram";
    }

    return 0;
}

//ANS:=
//Valid Anagram