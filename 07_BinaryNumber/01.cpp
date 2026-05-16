#include <iostream>
using namespace std;

void binToDec(int binNum){
    int n =binNum;
    int decNum=0;
    int pow=1;

    while (n>0){
        int lastDig=n%10;
        decNum+= lastDig*pow;
        pow=pow*2;
        n=n/10;
    }
    cout<<decNum<<endl;
}

int main(){
    binToDec(1010);
    return 0;
}
//last didgit n 2 ni 0 power sathe gunvanu e prmane agd power vadhrta jai guno n add karta jaav badhane 
//ex= 2^3*1 + 2^2*0 + 2^1*1 + 2^0*0 = 10

//ANS:=
//10
