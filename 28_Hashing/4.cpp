//  Check element existence using unordered_set

#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int> st;

    // Insert
    st.insert(10);
    st.insert(20);
    st.insert(30);

    // Print
    cout << "Elements:\n";
    for(int x : st){
        cout << x << " ";
    }
    cout << endl;

    // Search
    int key = 20;
    if(st.find(key) != st.end())
        cout << key << " Found\n";
    else
        cout << key << " Not Found\n";

    return 0;
}

//ANS:=
// Elements:
// 30 20 10 
// 20 Found