#include <iostream>
using namespace std;
int main(){
 int income;
 float tax;
 cout<<"enter your incom(in lakh)= ";
 cin>>income;

 if(income<5){
    tax=0;
 }else if(income<=10){
    tax=0.2*income;
 }else {
    tax=0.3*income;
 }

 cout<<"tax= "<<(tax*100000)<<endl;

    return 0;
}
//if  false thy to j if else ma jay baki na jay only if vada ma badhama j jay false hoik na hoi


//ANS:=
// enter your incom(in lakh)= 5
// tax= 100000