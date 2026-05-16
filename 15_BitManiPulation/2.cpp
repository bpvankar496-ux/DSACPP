//one's & second's compliment
//~=>NOT=>true=false,false=true
//ama normaly nathi thtu k ~6 nu 1 thvu joi pn -7 thy ch e 32 byte vadu 1's 2's complimwnt thi thy ch
//binary ma + mate=>same=false(0),diff=true(1)

// Original ~4=00000100
// NOT=>flip karo=11111011//1 pelu ch msb je nkki kare k sankhya - ma avse 0 hot to + n pachdna 7 magnitude 
// 1st =>flip 7 nu magnitude vadu=0000100
// 2nd=> +1 karo 0000101 ans je 5 so final ans -5
//inshot 1st ank nishani nkki kre n pachda ank ma +1 kro e ans 

//short cut ==>~a=>(-(a+1))
#include <iostream>
using namespace std;
int main(){

    cout<<(~4)<<endl;//-5==>-(4+1)short cut
    cout<<(~6)<<endl;//-7
    cout<<(~0)<<endl;//-1
    

    return 0;
}

// ANS:=
//-5
//-7
//-1