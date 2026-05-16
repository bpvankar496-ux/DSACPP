//array pass by reference =>int main ma array full hoi function ma array pointer bani jay ch 
#include <iostream>
using namespace std;

void printArr(int nums[],int n)//int *nums lakho k int nums[] banne sarkhu j km k pass by refrence function ma array pointer bani jay
{
    for (int i=0;i<n;i++){
        cout<<nums[i]<<",";
    }
    cout<<endl;
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);

    cout<<"array size = "<<sizeof(arr)<<endl;
    cout<<"int size = "<<sizeof(int)<<endl;
    cout<<"n ="<<n <<endl;
    printArr(arr ,n) ;
    return 0;
}

// ANS:=
// array size = 20
// int size = 4
// n =5
// 1,2,3,4,5,