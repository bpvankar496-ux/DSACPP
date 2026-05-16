//build and insert hashing
#include <iostream>
using namespace std;

// Node for linked list (chaining)
class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string k, int v) {
        key = k;
        val = v;
        next = NULL;
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    //  Hash Function
    int HashFunction(string key) {
        int idx = 0;
        int p = 1;

        for (int i = 0; i < key.length(); i++) {
            idx = (idx + key[i] * p) % totSize;
            p = (p * 31) % totSize;
        }
        return idx;
    }

public:
    //  Constructor
    HashTable(int size = 7) {
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];

        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    //  Insert (chaining)
    void insert(string key, int val) {
        int idx = HashFunction(key);

        Node* newNode = new Node(key, val);

        // Insert at head (chaining)
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;
    }

    //  Search
    int search(string key) {
        int idx = HashFunction(key);
        Node* temp = table[idx];

        while (temp != NULL) {
            if (temp->key == key) {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    //  Print table
    void print() {
        for (int i = 0; i < totSize; i++) {
            cout << i << " -> ";
            Node* temp = table[i];

            while (temp != NULL) {
                cout << "(" << temp->key << "," << temp->val << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

// Driver
int main() {
    HashTable ht;

    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("mango", 30);
    ht.insert("grapes", 40);

    ht.print();

    cout << "Search apple: " << ht.search("apple") << endl;

    return 0;
}

//ANS:=
// 0 -> NULL
// 1 -> (grapes,40) -> (apple,10) -> NULL
// 2 -> (mango,30) -> (banana,20) -> NULL
// 3 -> NULL
// 4 -> NULL
// 5 -> NULL
// 6 -> NULL
// Search apple: 10