//print n to 1
#include <iostream>
using namespace std;

void print(int n) {
    if(n == 0) {
        return;
    }
    cout << n << " "; //kaam
    print(n-1); //faith, next call
}

int main() {
    print(5);
    return 0;
}
// print(5) → 5, print(4)
// print(4) → 4, print(3)
// print(3) → 3, print(2)
// print(2) → 2, print(1)
// print(1) → 1, print(0)
// print(0) → return

//ANS:=
//5 4 3 2 1

//print 1 to n
#include <iostream>
using namespace std;

void print(int n) {
    if(n == 0) {
        return;
    }
    print(n-1); //faith, next call
    cout << n << " "; //kaam
}

int main() {
    print(5);
    return 0;
}

//ANS:=
//1 2 3 4 5