//convert in lowercase
#include <iostream>
using namespace std;

void toUpper(char word[], int n) {

    for(int i = 0; i < n; i++) {
        char ch = word[i];

        if(ch >= 'a' && ch <= 'z') { 
          continue;
     } else {
          word[i] = ch - 'A' + 'a';
     }
    }
}

int main() {
    char word[100];

    cout << "Enter a string: ";
    cin.getline(word, 100);

    int n = 0;
    while(word[n] != '\0') {
        n++;
    }

    toUpper(word, n);

    cout << word;

    return 0;
}

//ANS:=
//Enter a string: BHOOmIKA
//bhoomika