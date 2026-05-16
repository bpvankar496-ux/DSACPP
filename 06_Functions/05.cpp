#include <iostream>
using namespace std;

int facto(int n){
    int facto=1;
    for(int i=1;i<=n;i++){
    facto=facto*i;
}
    cout<<"factorioual("<<n<<")="<<facto<<endl;
    return facto;
}

int binocoffic(int n,int r){
int val1=facto(n);
int val2=facto(r);
int val3=facto(n-r);

int result=val1/(val2*val3);
return result;
}

int main(){
    cout<<binocoffic(5,3)<<endl;
    return 0;

}
// ANS:=
// factorioual(5)=120
// factorioual(3)=6
// factorioual(2)=2
// 10

