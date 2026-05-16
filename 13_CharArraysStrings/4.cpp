//palindrom ...e je agdthi n pachdthi vache to same j vanchy
#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char str[], int n) {
    int st = 0, end = n - 1;

    while(st < end) {
        if(str[st++] != str[end--]) {
            cout << "not valid palindrome\n";
            return false;
        }
    }

    cout << "valid palindrome\n";
    return true;
}

int main() {
    char str[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    isPalindrome(str, strlen(str));

    return 0;
}

// ANS:=
// Enter a string: MAAM
// valid palindrome