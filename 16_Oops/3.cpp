#include <iostream>
using namespace std;

class User {
private:
    int id;
    string password;

public:
    string username;

    User(int id) {
        this->id = id;
    }

    // Getter
    string getPassword() {
        return password;
    }

    // Setter
    void setPassword(string password) {
        this->password = password;
    }
};

int main() {
    User user1(101);
    user1.username = "BhoomikaVankar";
    user1.setPassword("harmi831224");

    cout << "username : " << user1.username << endl;
    cout << "password : " << user1.getPassword() << endl;

    return 0;
}

// ANS:=
// username : BhoomikaVankar
// password : harmi831224