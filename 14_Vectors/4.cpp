//Memory Leak  =>memory lai (new) ane free (delete) na kariye to → memory waste thai jay
#include <iostream>
using namespace std;

int main(){
    int *p = new int;

    *p = 100;
    cout << *p << endl;

    delete p;  // memory free kari  aa na hoi to memory leak

    return 0;
}

//ANS:=
//100