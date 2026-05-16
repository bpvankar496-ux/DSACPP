//Static Keyword==> Static variable badha objects vacche share thy - ekj copy.
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    static int count;  

    Student(string n) {
        name = n;
        count++;
    }
};

int Student::count = 0;  // Outside define complsary

int main() {
    Student s1("Raj");
    Student s2("Amit");
    Student s3("Priya");
    
    cout << "Total students: " << Student::count << endl;  // → 3
    return 0;
}
