//A Trie is a special tree used to store strings/words. prefix tree
//. Trie Introduction / Build Trie DS
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

int main() {

    TrieNode* root = new TrieNode();

    cout << "Trie Created";

    return 0;
}

//ANS:=
//Trie Created