//print string word differnt way str na badha  character ne ek ek karine ch ma muke
#include <iostream>
#include <string>
using namespace std;
int main(){
 
     string str = "Bhoomika Vankar!";
    // for(int i=0; i<str.length(); i++) {
    //     cout << str[i] << "-";
    // }
    // cout << "\n";

    for(char ch : str) {
        cout << ch << " ";
    } //shortcut

    cout << endl;
    return 0;
}
//ANS:=
//B h o o m i k a   V a n k a r ! 