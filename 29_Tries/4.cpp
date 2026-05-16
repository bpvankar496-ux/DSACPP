//StartsWith / Prefix Search in Trie
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

    // PREFIX SEARCH
    bool startsWith(string prefix) {

        TrieNode* curr = root;

        for(int i=0; i<prefix.size(); i++) {

            int idx = prefix[i] - 'a';

            if(curr->children[idx] == NULL) {
                return false;
            }

            curr = curr->children[idx];
        }

        return true;
    }
};

int main() {

    Trie t;

    t.insert("cat");
    t.insert("care");
    t.insert("dog");

    cout << t.startsWith("ca") << endl;
    cout << t.startsWith("do") << endl;
    cout << t.startsWith("xy") << endl;

    return 0;
}
// ANS:=
// 1
// 1
// 0