//Creating Dynamic Array =>runtime ma size decide kari ne array banavvu

#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int *arr = new int[n];  // dynamic array

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    delete[] arr;  // free memory
    return 0;
}

//ANS:=
// Enter size: 5
// 1 22 3 456 7
// 1 22 3 456 7

// Enter size: 5
// 1 34 5 7 8 45
// 1 34 5 7 8 
// delete[] arr extra memory delete kare  