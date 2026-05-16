// Class → blueprint hoy che object banava mate
// Object → class nu real instance (actual use ma avtu)
// Private → data ne direct access thi protect kare (outside thi access nai) ...aane cout print na kary error ave
// Public → data/function ne bahar thi access kari shakay
// Getter → private data ni value read (get) karva mate use thay
// Setter → private data ni value set/update karva mate use thay

#include <iostream>
using namespace std;

class User {
private:
    int id;
    string username;
    string password;
    string bio;

public:
    // Setters
    void setId(int i) {
        id = i;
    }

    void setUsername(string u) {
        username = u;
    }

    void setPassword(string p) {
        password = p;
    }

    void setBio(string b) {
        bio = b;
    }

    // Getters
    int getId() {
        return id;
    }

    string getUsername() {
        return username;
    }

    string getBio() {
        return bio;
    }

    // Methods
    void deactivate() {
        cout << "Deleting account\n";
    }

    void editBio(string newBio) {
        bio = newBio;
    }

    void display() {
        cout << "ID: " << getId() << endl;
        cout << "Username: " << getUsername() << endl;
        cout << "Bio: " << getBio() << endl;
    }
};

int main() {
    User s1;

    // Using setters
    s1.setId(1);
    s1.setUsername("bhoomika");
    s1.setPassword("1234");
    s1.setBio("Hello world!");

    // Display
    s1.display();

    // Edit bio
    s1.editBio("Updated bio here");
    cout << "\nAfter updating bio:\n";
    s1.display();

    // Deactivate
    cout << "\n";
    s1.deactivate();

    return 0;
}
// ANS:=
// ID: 1
// Username: bhoomika
// Bio: Hello world!

// After updating bio:
// ID: 1
// Username: bhoomika
// Bio: Updated bio here

// Deleting account