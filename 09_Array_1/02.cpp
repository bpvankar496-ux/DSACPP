//array ma maximum n minimum sodho
#include <iostream>
using namespace std;

int main() {

 int arr[]={5,6,9,12};
 int n =sizeof(arr)/sizeof(int);

     int max=arr[0];
     int min=arr[0];

for(int i=0; i<n; i++){
if (arr[i]>max){
    max=arr[i];
}
if(arr[i]<min){
    min=arr[i];
} 

}
cout<<"max="<<max<<endl;
cout<<"min="<<min<<endl;
    return 0;
}

//ANS:=
// max=12
// min=5