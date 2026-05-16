//MIN abs different
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    vector<int> A = {1,2,3};
    vector<int> B = {3,1,2};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;

    for(int i = 0; i < A.size(); i++) {
        absDiff += abs(A[i] - B[i]);
    }

    cout << "MIN abs diff = " << absDiff << endl;

    return 0;
}

//ANS:=
//MIN abs diff = 0