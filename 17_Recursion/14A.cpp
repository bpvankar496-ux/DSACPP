// Q2: Array ma key na badha indices print karo recursively
#include <iostream>
using namespace std;

void allOccurences(int arr[], int key, int i, int n) {
    if(i == n) {
        return;
    }

    if(arr[i] == key) {
        cout << i << " ";
    }
    allOccurences(arr, key, i+1, n);
}

int main() {
    int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int key = 2, n = 9;
    allOccurences(arr, key, 0, n);
    cout << endl;
    return 0;
}
//ANS:=
//1 5 7 8