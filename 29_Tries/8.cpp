//Count Unique Substrings using Trie
#include <iostream>
using namespace std;

class TrieNode {
public:

    TrieNode* children[26];

    TrieNode() {

        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
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

            curr = curr->children[idx];
        }
    }

    // COUNT NODES
    int countNodes(TrieNode* node) {

        if(node == NULL) {
            return 0;
        }

        int count = 0;

        for(int i=0; i<26; i++) {

            count += countNodes(node->children[i]);
        }

        return count + 1;
    }
};

// COUNT UNIQUE SUBSTRINGS
int countUniqueSubstr(string str) {

    Trie trie;

    // insert all suffixes
    for(int i=0; i<str.size(); i++) {

        string suffix = str.substr(i);

        trie.insert(suffix);
    }

    return trie.countNodes(trie.root);
}

int main() {

    string str = "ababa";

    cout << "Unique Substrings = "
         << countUniqueSubstr(str)
         << endl;

    return 0;
}

//ANS:=
//Unique Substrings = 10