//word break in tries

#include <iostream>
#include <vector>
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
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->endOfWord = true;
    }

    // SEARCH
    bool search(string word) {

        TrieNode* curr = root;

        for(int i=0; i<word.size(); i++) {

            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {
                return false;
            }

            curr = curr->children[idx];
        }

        return curr->endOfWord;
    }
};

// Recursive helper
bool helper(Trie &trie, string key) {

    // base case
    if(key.size() == 0) {
        return true;
    }

    for(int i=1; i<=key.size(); i++) {

        string firstPart = key.substr(0, i);
        string secondPart = key.substr(i);

        // first valid && remaining valid
        if(trie.search(firstPart) &&
           helper(trie, secondPart)) {

            return true;
        }
    }

    return false;
}

// Word Break
bool wordBreak(vector<string> dict, string key) {

    Trie trie;

    // build trie
    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]);
    }

    return helper(trie, key);
}

int main() {

    vector<string> dict = {
        "i",
        "like",
        "sam",
        "samsung",
        "mobile",
        "ice"
    };

    cout << wordBreak(dict, "ilikesam") << endl;

    return 0;
}

//ANS:=
//1