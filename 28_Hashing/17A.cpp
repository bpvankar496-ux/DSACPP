//Question 3 : Sort Characters By Frequency
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string frequencySort(string s) {

    unordered_map<char,int> freq;

    for(char ch : s) {
        freq[ch]++;
    }

    vector<pair<char,int>> vec(freq.begin(), freq.end());

    sort(vec.begin(), vec.end(),
        [](pair<char,int> a, pair<char,int> b) {
            return a.second > b.second;
        });

    string ans = "";

    for(auto p : vec) {

        ans += string(p.second, p.first);
    }

    return ans;
}

int main() {

    string s = "tree";

    cout << frequencySort(s);

    return 0;
}

//ANS:=
//eert