// Mode of Inheritance ==> Mode of Inheritance e decide kare che ke Base class na members, Derived class ma aavya pachi ketli accessibility (access) rakhe che. 3 modes hoy che: public, protected, private.
// Public Inheritance ==> Jyare : public lakho tyare Base class na public members, Derived class ma pan public j rahe che ane protected members, protected rahe che. Private members direct access thata nathi.
// Protected Inheritance ==> Jyare : protected lakho tyare Base class na public ane protected banne members, Derived class ma protected bani jay che.
// Private Inheritance ==> Jyare : private lakho tyare Base class na public ane protected banne members, Derived class ma private bani jay che etle bahar thi direct access kari sakata nathi.

// BaseClassMember   PublicInheritance   ProtectedInheritance  PrivateInheritance  
// public                public            protected              private
// protected             protected         protected             private
// private               Not accessible    Not accessible        Not accessible

#include <iostream>
using namespace std;

class Base {
public:
    int pub = 10;       // public member
protected:
    int prot = 20;      // protected member
private:
    int priv = 30;      // private member - ક્યારેય inherit નહીં થાય
};

//  PUBLIC Inheritance (સૌથી વધુ વપરાય)
class PublicChild : public Base {
public:
    void show() {
        cout << "pub = " << pub << endl;    //  public રહ્યું
        cout << "prot = " << prot << endl;  // protected રહ્યું
        // cout << priv;   Error - access નહીં
    }
};

//  PROTECTED Inheritance
class ProtectedChild : protected Base {
public:
    void show() {
        cout << "pub = " << pub << endl;    //  protected બની ગયું
        cout << "prot = " << prot << endl;  // protected રહ્યું
        // cout << priv;   Error
    }
};

//  PRIVATE Inheritance
class PrivateChild : private Base {
public:
    void show() {
        cout << "pub = " << pub << endl;    // private બની ગયું
        cout << "prot = " << prot << endl;  //  private બની ગયું
        // cout << priv;   Error
    }
};

int main() {
    PublicChild pc;
    pc.pub = 100;   // બહારથી access થાય (public છે)
    pc.show();
    
    ProtectedChild ptc;
    // ptc.pub = 100;  Error - protected છે, બહારથી નહીં
    ptc.show();
    
    PrivateChild pvc;
    // pvc.pub = 100;  Error - private છે
    pvc.show();
    
    return 0;
}
// ANS:=
// pub = 100
// prot = 20
// pub = 10
// prot = 20
// pub = 10
// prot = 20