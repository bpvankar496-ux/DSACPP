//  Store unique sorted elements using set

#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> st;

    // Insert
    st.insert(5);
    st.insert(1);
    st.insert(3);
    st.insert(1); // duplicate (ignored)

    // Print (sorted unique)
    cout << "Set elements:\n";
    for(int x : st){
        cout << x << " ";
    }
    cout << endl;

    // Search
    int key = 3;
    if(st.find(key) != st.end())
        cout << key << " Found\n";

    return 0;
}

// ANS:=
// Set elements:
// 1 3 5 
// 3 Found