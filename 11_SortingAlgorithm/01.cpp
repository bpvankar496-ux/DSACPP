//bubble short=>chdta k utrta krmam shorting
//time compl.=O(n^2)
//METHOD 1
#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        bool isSwap = false;
        for(int j=0; j<n-i-1; j++) { //n-i-1  ch km k jo 1st round ma 5 moto hoi to e last elemt thai jase pachi ene compare karvani jarur nathi,badha round ma avu thse
            if(arr[j] > arr[j+1])//utrta krm ma joi to < muko
             {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            //array is already sorted
            break;
        }
    }

    print(arr, n);
}

int main() {
     int arr[6] = {5, 4, 1, 3, 2};
    bubbleSort(arr, 5);
    return 0;
}




//METHOD 2
//WITHOUT FUNCTION
#include <iostream>
using namespace std;

int main() {

    int arr[] = {5,4,1,3,2};
    int n = 5;

    for(int i=0; i<n; i++) {

        for(int j=0; j<n-i-1; j++) {

            if(arr[j] > arr[j+1]) {

                swap(arr[j], arr[j+1]);

            }
        }
    }

    for(int i=0; i<n; i++) {

        cout << arr[i] << " ";

    }

    return 0;
}
//ANS:=
//1 2 3 4 5