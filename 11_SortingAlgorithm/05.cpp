//inbuilt sort in c++

//METHOD 1
//aa 6 e 6 question ma aa rit thi thai jay inbuilt ave only sort() use thi code simple & TIME COM. BI O(n log n) SARIII
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int arr[] = {4,8,8,3,2,4,9,9,1,6};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, arr+n);//accending
    //sort(arr, arr+n, greater<int>()); decending
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
//METHOD 2
#include <iostream>
#include <climits>
#include <algorithm> 

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
    int arr[8] = {2,4,9,2,7,7,3,4};
    sort(arr,arr+8);
    //sort(arr+5,arr+8,greater<int>());decending mate
    print(arr, 8);
    return 0;
}



//ANS:=
//2 2 3 4 4 7 7 9 