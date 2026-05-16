//pointer arithematic-1
#include <iostream>
using namespace std;

int main() {
int a=5;
int *ptr=&a;

cout<<ptr<<endl;
ptr++;
cout<<ptr<<endl;
ptr--;
cout<<ptr<<endl;
cout<<&a<<endl;
cout<<*ptr<<endl;

    return 0;

}

//ptr++ no matlb jo int hoi to int++ mtlb byte ma + thy na k sankhy ch ch to 1 byte int ma 4 jo 
//int hoi to 100 thi 105 n ch hoi 100 thii 101 
//terminal ma smjva mate decimal prmne last didgit  jovano ema 1 t0 9 pachi a  thi f  loop ma chale

// ANS:=
// 0x61ff08
// 0x61ff0c
// 0x61ff08
// 0x61ff08
// 5