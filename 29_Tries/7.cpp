//start with prefix or not
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:

    unordered_map<char, Node*> children;

    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {

    Node* root;

public:

    Trie() {
        root = new Node();
    }

    // INSERT
    void insert(string word) {

        Node* temp = root;

        for(int i=0; i<word.size(); i++) {

            char ch = word[i];

            if(temp->children.count(ch) == 0) {

                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }

    // SEARCH
    bool search(string key) {

        Node* temp = root;

        for(int i=0; i<key.size(); i++) {

            char ch = key[i];

            if(temp->children.count(ch)) {

                temp = temp->children[ch];
            }
            else {

                return false;
            }
        }

        return temp->endOfWord;
    }

    // STARTS WITH
    bool startsWith(string prefix) {

        Node* temp = root;

        for(int i=0; i<prefix.size(); i++) {

            char ch = prefix[i];

            if(temp->children.count(ch)) {

                temp = temp->children[ch];
            }
            else {

                return false;
            }
        }

        return true;
    }
};

int main() {

    Trie t;

    t.insert("apple");
    t.insert("app");
    t.insert("mango");

    cout << t.startsWith("app") << endl;
    cout << t.startsWith("man") << endl;
    cout << t.startsWith("cat") << endl;

    return 0;
}

//ANS:=
// 1
// 1
// 0