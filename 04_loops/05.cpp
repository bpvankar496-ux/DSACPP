//num is prime or not?
//be rite thy prime number pote n 1 vade j mmultiple hoi to thy to e hisbe 2 to n-1 le ,
//bijo sqrt(n) l mtlb n-1 etl badha sodhvani jarur nai 1 lo j madi gayo dividiabal to stop ty aj  e root jetlu hoi j
// 2to rout n mat i*i>=n pn lkhy

//METHOD 1
#include<iostream>
using namespace std;
int main(){
    int n;
cout<<"enter number= ";
cin>>n;
 bool isprime=true;
 
    for (int i=2;i<=n-1;i++){
    if(n%i==0){
    isprime=false;
    break;
    }
}
    if(isprime==true){
    cout<<"prime number"<<endl;
     } else{
    cout<<"non prime number"<<endl;}
    return 0;
}

//METHOD 2

#include<iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
cout<<"enter number= ";
cin>>n;
 bool isprime=true;
 
    for (int i=2;i<=sqrt(n);i++){
    if(n%i==0){
    isprime=false;
    break;
    }
}
    if(isprime==true){
    cout<<"prime number"<<endl;
     } else{
    cout<<"non prime number"<<endl;}
    return 0;
}


// //ANS:=
//enter number= 5
//prime number