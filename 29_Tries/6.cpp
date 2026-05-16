//prefix problem in tries
#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;
    int freq;

    TrieNode() {

        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }

        endOfWord = false;
        freq = 1;
    }
};

class Trie {

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // INSERT
    void insert(string word) {

        TrieNode* curr = root;

        for(int i=0; i<word.size(); i++) {

            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {

                curr->children[idx] =
                    new TrieNode();

            }
            else {

                curr->children[idx]->freq++;
            }

            curr = curr->children[idx];
        }

        curr->endOfWord = true;
    }

    // GET UNIQUE PREFIX
    string getPrefix(string word) {

        TrieNode* curr = root;

        string prefix = "";

        for(int i=0; i<word.size(); i++) {

            int idx = word[i] - 'a';

            prefix += word[i];

            if(curr->children[idx]->freq == 1) {
                return prefix;
            }

            curr = curr->children[idx];
        }

        return prefix;
    }
};

void prefixProblem(vector<string> dict) {

    Trie trie;

    // build trie
    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]);
    }

    // print unique prefixes
    for(int i=0; i<dict.size(); i++) {

        cout << trie.getPrefix(dict[i])
             << endl;
    }
}

int main() {

    vector<string> dict = {
        "zebra",
        "dog",
        "duck",
        "dove"
    };

    prefixProblem(dict);

    return 0;
}

// ANS:=
// z
// dog
// du
// dov