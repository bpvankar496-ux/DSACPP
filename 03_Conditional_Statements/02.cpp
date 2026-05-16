#include<iostream>
using namespace std;
int main(){
    int a,b,c;

    cout<<"enter a= ";
    cin>>a;
    cout<<"enter b= ";
    cin>>b;
    cout<<"enter c= ";
    cin>>c;

    if(a>=b && a>=c){
        cout<<"larger num is="<<a<<endl;
    }else if(b>c){
        cout<<"larger num is= "<<b<<endl;
    }else{
        cout<<"larger num is= "<<c<<endl;
    }
    return 0;

}


//ANS:=
// enter a= 6
// enter b= 9
// enter c= 5
// larger num is= 9