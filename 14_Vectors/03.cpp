//static vs Dynamic Allocation =>static = fixed size, dynamic = changeable size
#include <iostream>
using namespace std;

int main(){

    // static
    int arr1[5] = {1,2,3,4,5};

    // print arr1
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
    }

    cout<<endl;

    // dynamic
    int n = 5;
    int *arr2 = new int[n];

    //  print arr2
    for(int i=0;i<n;i++){
    arr2[i] = i+1;
    cout<<arr2[i]<<" ";
}

    delete[] arr2;

    return 0;
}

//ANS:=
//1 2 3 4 5 
//1 2 3 4 5  