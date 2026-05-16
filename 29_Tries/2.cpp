//Insert in Trie
#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {

        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }

        endOfWord = false;
    }
};

class Trie {

    TrieNode* root;

public:

    Trie() {
        root = new TrieNode();
    }

    // INSERT
    void insert(string word) {

        TrieNode* curr = root;

        for(int i=0; i<word.size(); i++) {

            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->endOfWord = true;
    }

    void printSearch(string word) {

        TrieNode* curr = root;

        for(int i=0; i<word.size(); i++) {

            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {
                cout << "Not Found\n";
                return;
            }

            curr = curr->children[idx];
        }

        if(curr->endOfWord)
            cout << "Found\n";
        else
            cout << "Not Found\n";
    }
};

int main() {

    Trie t;

    t.insert("cat");
    t.insert("care");
    t.insert("dog");

    t.printSearch("cat");

    return 0;
}

//ANS:=
//Found