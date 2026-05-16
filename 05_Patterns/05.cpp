//charter pyramid
#include<iostream>
using namespace std;
int main(){
    int n=5;
    char ch='A';
    for (int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
    return 0;
}


//ANS:=
// A 
// B C 
// D E F 
// G H I J 
// K L M N O 