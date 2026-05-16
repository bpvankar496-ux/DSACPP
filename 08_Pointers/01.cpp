#include <iostream>
using namespace std;

int main(){
 int x=5,y=10;
 int *ptr1=&x, *ptr2=&y;
 ptr2=ptr1;//ptr 2 ni value ptr 1 ma assign kari y=x....x=x..y=x

cout<<ptr1<<endl;//x no add
cout<<ptr2<<endl;//x no add
cout<<&x<<endl;//x no add
cout<<&y<<endl;//y no add
cout<<*ptr2<<endl;//x=5
cout<<*ptr1<<endl;//x=5
}

// ANS:=
// 0x61ff04
// 0x61ff04
// 0x61ff04
// 0x61ff00
// 5
// 5