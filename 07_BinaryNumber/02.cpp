#include <iostream>
using namespace std;

void decToBin(int decNum){
    int n=decNum;
    int pow=1;
    int binNum=0;

    while (n>0){
        int rem=n%2;
        binNum+=rem*pow;
        n=n/2;
        pow=pow*10;
    }
    cout<<binNum<<endl;
}
int main(){
decToBin(10);
return 0;
}

// binNum = 0 + 0*1= 0
// binNum = 0 + 1*10= 10
// binNum = 10 + 0*100= 10
// binNum = 10 + 1*1000= 1010

//4 n 2 vade module kadhta javnu jya sudhi 0 na thy n badha je sesh ma vdhe e ultethi lkhvana e j number thy ch baki 10 vade guno   ght 0,1,2...em to e logic

//ANS:=
//1010