//left side binary operator=>(<<)=>formula=>a<<b=>a*2^b
//right side binary operator=>(>>)=>formula=>a>>b=>a/2^b

//6<<1=>00000110 →  00001100 ==>ama left side ch enu binary form lkho n right side apyu ch etla akda left side(bcz<<) na gayb karo baki je jgya ena lidhe vadhe right ma tya 0 n e sankhya ans
//6>>2=>000000110 → 00000001==>ama 6 nu binary form lkhyu right ma 2 apela ch so right side(bcz>>) ma 2 gayb karo baki empty jagya left baju 0 muko e j ans

#include <iostream>
using namespace std;
int main(){

    cout<<(6>>2)<<endl;//a/2^b
    cout<<(6<<1)<<endl;//a*2^b
    

    return 0;
}

//ANS:=
//1
//12