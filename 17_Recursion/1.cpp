//Recursion==> Function potane j varvar  call kare tyare tene Recursion kahevay
//print factorioul
#include <iostream>
using namespace std;

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    int ans = factorial(4);
    cout << ans << endl;
    return 0;
}
//ANS:=
//24