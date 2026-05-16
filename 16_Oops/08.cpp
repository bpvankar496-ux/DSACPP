//  Multi-level Inheritance==>Grandparent → Parent → Child (સાંકળ જેવું)
#include<iostream>
using namespace std;

class GrandFather {
public:
    void property() {
        cout << "Dada ni  Property: 10 vingha jamin " << endl;
    }
};

class Father : public GrandFather {
public:
    void business() {
        cout << "pita no  Business: shope" << endl;
    }
};

class Son : public Father {   // Son ne Father + GrandFather bnne na guno
public:
    void skills() {
        cout << "son ni Skill: Computer Engineer " << endl;
    }
};

int main() {
    Son s;
    
    s.property();   // GrandFather ni(2 level upp)
    s.business();   // Father ni(1 level upp)
    s.skills();     // potani
    
    return 0;
}
// ANS:=
// Dada ni  Property: 10 vingha jamin 
// pita no  Business: shope
// son ni Skill: Computer Engineer