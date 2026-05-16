//counting sort
// Pela counting karo
// Pachi sorted order ma values lakho
//METHOD 1
#include <iostream>
#include <climits>

using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(int arr[], int n) {
    int freq[100000] = {0}; //range
    int minVal = INT_MAX, maxVal = INT_MIN;

    //1st step - O(n)
    for(int i=0; i<n; i++) {
        freq[arr[i]]++;
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    //2nd step - O(range) = max - min
    for(int i=minVal, j=0; i<=maxVal; i++) {
        while(freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }

    print(arr, n);
}

int main() {
    int arr[] = {2,4,9,2,7,7,3,4};
    int n = 8;
    countSort(arr, n);
    return 0;
}

//METHOD 2

#include <iostream>
using namespace std;

int main() {

    int arr[] = {2,4,9,2,7,7,3,4};
    int n = 8;

    int freq[10] = {0};

    //count frequency
    for(int i=0; i<n; i++) {

        freq[arr[i]]++;

    }

    //sorted array print
    for(int i=0; i<10; i++) {

        while(freq[i] > 0) {

            cout << i << " ";

            freq[i]--;
        }
    }

    return 0;
}

//ANS:=
//2 2 3 4 4 7 7 9 