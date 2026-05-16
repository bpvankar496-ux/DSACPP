#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;

    for(int i=0; i<5; i++) {
        vec.push_back(i);
    }

    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    return 0;
}
//capicity dar khte double thy jo gya na hoi to ne te j capicity ch
// ANS:=
// 5
// 8