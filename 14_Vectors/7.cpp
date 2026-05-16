//vector implitation
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    cout << "size : " << vec.size() << endl;
    cout << "capacity : " << vec.capacity() << endl;

    vec.push_back(4);
    cout << "size : " << vec.size() << endl; //4
    cout << "capacity : " << vec.capacity() << endl; //6
    return 0;
}

// ANS:=
// size : 3
// capacity : 3
// size : 4
// capacity : 6