//array ni size input karavni n array mte na elemt bi ne arry apva e  output ma avse
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter length of array : ";
    cin >> n;

    int arr[n];
    cout<<"enter array elemnt :";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];//loop vgr cin na kary km k loop vgr em run thy pn sachu nai km k arr[n] kr dai to index to arr 0 thi 4 thy length 5 etle
         cout << arr[i] << ",";
    }
     cout<<endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;
    return 0;
}
// ANS:=
// enter length of array : 5
// enter array elemnt :34 5 9 0 234 
// 34,5,9,0,234,
// arr[0] = 34
// arr[1] = 5
// arr[2] = 9
// arr[3] = 0
// arr[4] = 234

