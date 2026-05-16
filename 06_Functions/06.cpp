//print range
#include <iostream>
using namespace std;

//perticuler number  prime ch k nai 
bool isprime(int n){
    if (n==1){
        return false;
    }for(int i =2;i*i<=n;i++)
    {
       if(n%i==0)
    return false;
    }
    return true;
}

//range ma ch prime e print karva mate 
void allprimes(int n){
    for (int i=2;i<=n;i++){
        if(isprime(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main(){
    allprimes(15);
    return 0;

}

// ANS:=
// 2 3 5 7 11 13