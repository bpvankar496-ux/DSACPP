//calculater if else thi

// #include <iostream>
// using namespace std;
// int main(){
//    int a,b;
//    char op;
    
//    cout<<"enter a= ";
//    cin>>a;
//    cout<<"enter b= ";
//    cin>>b;
//    cout<<"enter operator= ";
//    cin>>op;

//    if(op=='+'){
//     cout<<"a+b= "<<a+b<<endl;
//    }else if(op=='-'){
//     cout<<"a-b=  "<<a-b<<endl;
//    }else if(op=='*'){
//     cout<<"a*b= "<<a*b<<endl;
//    }else if(op='/'){
//     cout<<"a/b= "<<a/b<<endl;
//    }else{
//     cout<<"envalid operator"<<endl;
//    }
//     return 0;

// }


//switch thi calculator

#include<iostream>
using namespace std;
int main(){
 int a,b;
 char op;

 cout<<"enter a= ";
   cin>>a;
   cout<<"enter b= ";
   cin>>b;
   cout<<"enter operator= ";
   cin>>op;

 switch(op){
    case '+':cout<<"a+b= "<<a+b<<endl;
          break;
    case '-':cout<<"a-b= "<<a-b<<endl;
          break;
    case '*':cout<<"a*b= "<<a*b<<endl;
          break;
    case '/':cout<<"a/b= "<<a/b<<endl;
          break;
          default:cout<<"invalid operator";
 } 
    return 0;

}


//ANS:=
// enter a= 18
// enter b= 14
// enter operator= -
// a-b= 4