//  Store sorted key-value pairs using map

#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int,int> mp;

    // Insert
    mp[3] = 30;
    mp[1] = 10;
    mp[2] = 20;

    // Print (sorted order)
    cout << "Sorted Map:\n";
    for(auto x : mp){
        cout << x.first << " -> " << x.second << endl;
    }

    // Search
    int key = 2;
    if(mp.find(key) != mp.end())
        cout << "Found " << key << endl;

    return 0;
}

// ANS:=
// Sorted Map:
// 1 -> 10
// 2 -> 20
// 3 -> 30
// Found 2