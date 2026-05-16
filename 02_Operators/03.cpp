#include <iostream>
using namespace std;

int main() {
    int a = 5, b;

    b = ++a;
    cout << " a = " << a << ", b = " << b << endl;

    a = 5;
    b = a++;
    cout << " a = " << a << ", b = " << b << endl;

    a = 5;
    b = --a;
    cout << " a = " << a << ", b = " << b << endl;

    a = 5;
    b = a--;
    cout << " a = " << a << ", b = " << b << endl;

    return 0;
}
//a etle k jeni kimat apde apiye ch int ma already e normaly  sign prpane j =1 ke -1 thse pre post bnn ma 
// b jema lagviye a++,a--,++a,--a ema  POST ma use thy pachi update n PRE ma update thy pachi use 
//so post ma + hoi k - pela use thy etl b emne em j rahe int ma ch e j pre ma normal jevu j update thy +1 k -1
//inshot post increement decreement ma j b jem ch tem j re int same value pela use eetl baki badham ma +,- thy  j


//ANS:=
//  a = 6, b = 6
//  a = 6, b = 5
//  a = 4, b = 4
//  a = 4, b = 5