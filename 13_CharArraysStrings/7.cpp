#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello World";

    // 1. length()
    cout << str.length()<<  endl;       // Output: 11

    // 2. at(idx)
    cout << str.at(0)<<  endl;          // Output: H
    cout << str.at(6)<<  endl;          // Output: W

    // 3. substr(startIdx, size)
    cout << str.substr(6, 5)<<  endl;   // Output: World
    cout << str.substr(0, 5)<<  endl;   // Output: Hello

    // 4. find(word)
    cout << str.find("World")<<  endl;  // Output: 6
    cout << str.find("Hello")<<  endl;  // Output: 0 jo e word hoi j nai to random value avse pn jo value print karavo to answe -1 ave

    return 0;
}

// ANS:=
// 11
// H
// W
// World
// Hello
// 6
// 0