//list  in STL
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    // Insert front & back
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_front(5);
    // 5 -> 10 -> 20 -> 30

    // Delete front & back
    l.pop_back();   // 30 remove
    l.pop_front();  // 5 remove
    // 10 -> 20

    // Size
    cout << l.size() << endl;  // 2

    // Front & Back
    cout << l.front() << endl; // 10
    cout << l.back() << endl;  // 20

    // Print all
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Range based loop
    for (auto val : l) {
        cout << val << " ";
    }
    cout << endl;

    // Insert at position
    auto it = l.begin();
    it++;               // 2nd position par jao
    l.insert(it, 15);  // 10 -> 15 -> 20

    // Erase at position
    it = l.begin();
    it++;
    l.erase(it);  // 15 remove -> 10 -> 20

    // Empty check
    cout << l.empty() << endl;  // 0 (false)

    // Clear
    l.clear();
    cout << l.empty() << endl;  // 1 (true)

    return 0;
}

// ANS:=
// 2
// 10
// 20
// 10 20 
// 10 20 
// 0
// 1