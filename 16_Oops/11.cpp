//Hybrid Inheritance==>Multiple + Hierarchical નું Combination (Diamond Problem)
#include<iostream>
using namespace std;

class Vehicle {
public:
    void fuel() {
        cout << "Vehicle runs on fuel " << endl;
    }
};

class Car : virtual public Vehicle {   
public:
    void carFeature() {
        cout << "Car: 4 doors " << endl;
    }
};

class Truck : virtual public Vehicle { 
public:
    void truckFeature() {
        cout << "Truck: Heavy load " << endl;
    }
};
class SportsTruck : public Car, public Truck {
public:
    void features() {
        cout << "SportsTruck: Fast + Strong! " << endl;
    }
};

int main() {
    SportsTruck st;
    
    st.fuel();          // Vehicle(because of virtual  1copy)
    st.carFeature();    // Car 
    st.truckFeature();  // Truck 
    st.features();      // potani
    
    return 0;
}


// ## Summary 

// Single:        A → B

// Multi-level:   A → B → C

// Multiple:      A ↘
//                   → C
//                B ↗

// Hierarchical:      A
//                  / | \
//                 B  C  D

// Hybrid:        A
//               / \
//              B   C
//               \ /
//                D

// ANS:=
// Vehicle runs on fuel 
// Car: 4 doors 
// Truck: Heavy load 
// SportsTruck: Fast + Strong! 