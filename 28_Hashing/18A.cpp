//Question 4 : Bulls and Cows
#include <iostream>
#include <unordered_map>
using namespace std;

string getHint(string secret, string guess) {

    int bulls = 0;
    int cows = 0;

    unordered_map<char,int> mp;

    // count chars of secret
    for(char ch : secret) {
        mp[ch]++;
    }

    // bulls count
    for(int i=0; i<secret.size(); i++) {

        if(secret[i] == guess[i]) {

            bulls++;

            mp[guess[i]]--;
        }
    }

    // cows count
    for(int i=0; i<secret.size(); i++) {

        if(secret[i] != guess[i] &&
           mp[guess[i]] > 0) {

            cows++;

            mp[guess[i]]--;
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main() {

    string secret = "1807";
    string guess = "7810";

    cout << getHint(secret, guess);

    return 0;
}

//ANS:=
//1A3B