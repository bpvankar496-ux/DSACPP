// Question: Division operator / vaprya vagr integers ne divide karo
// Logic: Bit shifting thi divisor nr double karta jao → jetli vakht fit thyy ee count karo 

//type-1
#include <iostream>
#include <climits>
using namespace std;

int divide(int dividend, int divisor) {
    // handle overflow case
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;

    long a = abs(dividend);
    long b = abs(divisor);
    int ans = 0;

    while(a >= b) {
        int count = 0;
        while(a >= (b << (count + 1))) {
            count++;
        }
        ans += (1 << count);
        a -= (b << count);
    }

    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        return -ans;

    return ans;
}

int main() {
    cout << divide(10, 3) << endl;   // 3
    cout << divide(7, -2) << endl;   // -3
    return 0;
}

//type-2
#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
    int count = 0;
    int sign = 1;

    // sign check
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        sign = -1;

    // make positive
    dividend = abs(dividend);
    divisor = abs(divisor);

    // repeated subtraction
    while (dividend >= divisor) {
        dividend -= divisor;
        count++;
    }

    return sign * count;
}

int main() {
    cout << divide(10, 3) << endl;   // 3
    cout << divide(7, -2) << endl;   // -3
    return 0;
}

//ANS:=
//3
//-3