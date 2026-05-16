#include <iostream>
using namespace std;

int main() {
char ch='a';
char *ptr= &ch;

cout<<(void*)ptr<<endl;
ptr++;
cout<<(void*)ptr<<endl;
ptr--;
cout<<(void*)ptr<<endl;
cout << hex<< (int)*ptr << endl;// nichenu kostak prmane ..void.int,hex dec ....etc
cout<<ch<<endl;

    return 0;

}
//(void*) int ma chale ani bgr but char ma lkhvu pade km k aa string smji le etle na lkhe to ch j print kare addres nai  int joi e to (int)*ptr lkhvu
//*ptr actuall value n ptr e addres
// | Value | Meaning           |
// | ----- | ----------------- |
// | `a`   | character         |
// | `97`  | ASCII decimal     |
// | `61`  | ASCII hexadecimal |

//ANS:=
// 0x61ff0b
// 0x61ff0c
// 0x61ff0b
// 61
// a