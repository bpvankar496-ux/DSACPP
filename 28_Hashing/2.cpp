//Rehasing
#include <iostream>
using namespace std;

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
    int currSize;
    int totSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;
        int p = 1;

        for (int i = 0; i < key.length(); i++) {
            idx = (idx + key[i] * p) % totSize;
            p = (p * 31) % totSize;
        }
        return idx;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;

        // double size
        totSize = 2 * totSize;
        table = new Node*[totSize];

        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }

        currSize = 0;

        // re-insert all elements
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];

            while (temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
        }
    }

public:
    HashTable(int size = 5) {
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];
        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        // check load factor
        float loadFactor = (1.0 * currSize) / totSize;

        if (loadFactor > 0.7) {
            rehash();
        }
    }

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

int main() {
    HashTable ht;

    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("mango", 30);
    ht.insert("grapes", 40);
    ht.insert("orange", 50);

    ht.print();

    return 0;
}

// ANS:=
// 0 -> (apple,10) -> (mango,30) -> NULL
// 1 -> NULL
// 2 -> (grapes,40) -> NULL
// 3 -> NULL
// 4 -> NULL
// 5 -> NULL
// 6 -> (orange,50) -> NULL
// 7 -> NULL
// 8 -> NULL
// 9 -> (banana,20) -> NULL