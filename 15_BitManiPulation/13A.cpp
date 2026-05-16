//Question:Aapela number ma i thi j sudhina bits clear karo. 
#include <iostream>
using namespace std;

void clearBitsInRange(int num, int i, int j) {
    int a = (~0) << (j+1);
    int b = (1 << i) - 1;

    int mask = a | b;
    num = num & mask;

    cout << num << endl;
}

int main() {
    clearBitsInRange(15, 1, 3);
    return 0;
}
//ANS:=
//1