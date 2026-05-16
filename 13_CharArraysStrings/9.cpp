//operators
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";

    // 1. = (Assignment)
    string s3 = s1;
    cout << "Assignment: " << s3 << "\n";         // Hello

    // 2. + (Concatenation - jod)
    string s4 = s1 + " " + s2;
    cout << "Concat: " << s4 << "\n";             // Hello World

    // 3. += (Append)
    s1 += " Bhai";
    cout << "Append: " << s1 << "\n";             // Hello Bhai

    // 4. == (Equal check)
    cout << ("abc" == "abc") << "\n";             // 1 (true)
    cout << ("abc" == "xyz") << "\n";             // 0 (false)

    // 5. != (Not equal)
    cout << ("abc" != "xyz") << "\n";             // 1 (true)

    // 6. < > (Compare - alphabetical order)
    cout << ("apple" < "banana") << "\n";         // 1 (true)
    cout << ("mango" > "apple") << "\n";          // 1 (true)

    // 7. [] (Index - letter access)
    string s5 = "Hello";
    cout << "Index [1]: " << s5[1] << "\n";       // e

    // 8. >> cin (Input levo)
    // cin >> s5;   // user input

    return 0;
}

// ANS:=
// Assignment: Hello
// Concat: Hello World
// Append: Hello Bhai
// 1
// 0
// 1
// 1
// 1
// Index [1]: e