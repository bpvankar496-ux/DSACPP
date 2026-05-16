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
int main(){
    facto(0);
    facto(1);
    facto(2);
    facto(3);
    facto(4);
    facto(5);
    return 0;

}

//ANS:=
//factorioual(0)=1
//factorioual(1)=1
// factorioual(2)=2
// factorioual(3)=6
// factorioual(4)=24
// factorioual(5)=120
