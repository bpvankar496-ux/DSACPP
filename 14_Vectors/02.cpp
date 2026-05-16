//Dynamic Memory Allocation=>program chalta time memory levu (new thi)
#include <iostream>
using namespace std;

int main(){
    int *p = new int;  // memory allocate
    *p = 10;

    cout<<*p<<endl;

    delete p;  // memory free
    return 0;
}
//ANS:=
//10

// Stack	                Heap
// automatic memory	        manual memory
// fast	                    thodu slow
// compiler manage kare 	programmer manage kare
// local variables	        dynamic memory