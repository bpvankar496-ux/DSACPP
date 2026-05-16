//linear search =>elemnt sodhe ek ek element pr jai n jya sudhi na made
#include <iostream>
using namespace std;

int linearSearch(int *arr,int n,int key)  //int *arr lakho k int arr[] banne sarkhu j km k pass by refrence function ma array pointer bani jay
{
    for(int i=0;i<n; i++){
        if (arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={2,4,6,8,10,12,14,16};
    int n=sizeof(arr)/sizeof(int);
    cout<<linearSearch(arr,n,10)<<endl;
    return 0;
}
//index number return krse index 0 to n.. thy

//ANS:=
//4