//convert in upper case
#include <iostream>
using namespace std;

void toUpper(char word[], int n) {

    for(int i = 0; i < n; i++) {
        char ch = word[i];

        if(ch >= 'A' && ch <= 'Z') { // uppercase
            continue;
        } else { // lowercase
            word[i] = ch - 'a' + 'A';
        }
        
    }
}

int main() {
    char word[100];

    cout << "Enter a string: ";
    cin.getline(word, 100);//cin ek j sabd mate vpray jo cin ma space pachi lkhiye e exicute nai thy cin.getline vad ma thy

    int n = 0;
    while(word[n] != '\0') {
        n++;
    }

    toUpper(word, n);

    cout << word;

    return 0;
}
//ANS:=
// Enter a string: bHoomika
// BHOOMIKA