
//  Frequency count using unordered_map

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string,int> mp;

    // Insert
    mp["apple"]++;
    mp["banana"]++;
    mp["apple"]++;
    mp["mango"]++;

    // Print frequency
    cout << "Frequencies:\n";
    for(auto x : mp){
        cout << x.first << " -> " << x.second << endl;
    }

    // Search
    string key = "apple";
    if(mp.find(key) != mp.end())
        cout << key << " found with count " << mp[key] << endl;

    return 0;
}

// ANS:=
// Frequencies:
// mango -> 1
// banana -> 1
// apple -> 2
// apple found with count 2