//sum of all digit in  num
#include<iostream>
using namespace std;

int main(){
int n;
int digitsum=0;
    cout<<"enter number= ";
    cin>>n;
    while(n>0){
        int lastdigit=n%10;
        digitsum+=lastdigit;
        n=n/10;

    }
    cout<<"sum of digit= "<<digitsum<<endl;
    return 0;
}


//ANS:=
// enter number= 831
// sum of digit= 12