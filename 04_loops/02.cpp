//sum of only all odd didgit in  num
#include<iostream>
using namespace std;

int main(){
int n;
int digitsum=0;
    cout<<"enter number= ";
    cin>>n;
    while(n>0){
        int lastdigit=n%10;
        if (  lastdigit%2!=0)
        {
        digitsum+=lastdigit;}
        n=n/10;

    }
    cout<<"sum of odd digit= "<<digitsum<<endl;
    return 0;
}


//ANS:=
// enter number= 3285
// sum of odd digit= 8