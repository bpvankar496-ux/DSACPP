// Q2: Array માં n/2 થી વધારે વખત આવતો element શોધો
#include <iostream>
using namespace std;

int main() {
    int nums[] = {3, 2, 3};
    int n = 3;
    int candidate = nums[0], count = 1;

    for(int i = 1; i < n; i++) {
        if(nums[i] == candidate) {
            count++;
        } else {
            count--;
            if(count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }
    cout << candidate << endl;
    return 0;
}

//ANS:=
//3