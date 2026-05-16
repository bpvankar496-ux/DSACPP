//print digit in reverse form
//anathi ek ek karine digit print thy j endline api daie cout ma to new line ma digit ave endl apya vgr eksathe karvu hoi to type 2 baki type1 
//type1
#include<iostream>
using namespace std;

int main(){
int n;
int lastdigit=0;
    cout<<"enter number= ";
    cin>>n;
    while(n>0){
        int lastdigit=n%10;
        cout<<lastdigit;
        n=n/10;

    }
    cout<<endl;
    return 0;
}

//type 2

#include<iostream>
using namespace std;

int main(){
int n;
int res=0;
    cout<<"enter number= ";
    cin>>n;
    while(n>0){
        int lastdigit=n%10;
        res=res*10+lastdigit;
        n=n/10;

    }
    cout<<"reverse num= "<<res<<endl;
    return 0;
}



//ANS:= 
// enter number= 894
// reverse num= 498


// 0*10+4   4
//	4*10+3	43
//43*10+2	432
//	432*10+1 4321