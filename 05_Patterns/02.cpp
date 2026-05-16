//triangle pattern
#include<iostream>
using namespace std;
int main(){
    int n=5;
    for (int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }    
    
    return 0;
}


//ANS:=
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 
//inner loop i je che etla j star  j<=i thi tringle thyu jo j<=n to squre
//n ,n squre ,1 to n=innerloop
//n,i triangle ,1 to i=innerloop