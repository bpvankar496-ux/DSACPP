//Question 2 : Longest Word in Dictionary
#include <iostream>
#include <unordered_map>
#include <vector>
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

public:

    Node* root;

    Trie() {
        root = new Node();
    }

    // INSERT
    void insert(string word) {

        Node* temp = root;

        for(int i=0; i<word.size(); i++) {

            char ch = word[i];

            if(temp->children.count(ch) == 0) {

                temp->children[ch] =
                    new Node();
            }

            temp = temp->children[ch];
        }

        temp->endOfWord = true;
    }

    // DFS
    void longestHelper(Node* root,
                       string &ans,
                       string temp) {

        for(auto child : root->children) {

            char ch = child.first;
            Node* nextNode = child.second;

            if(nextNode->endOfWord) {

                temp += ch;

                if(temp.size() > ans.size() ||
                  (temp.size() == ans.size()
                   && temp < ans)) {

                    ans = temp;
                }

                longestHelper(nextNode,
                              ans,
                              temp);

                temp.pop_back();
            }
        }
    }

    string longestWord() {

        string ans = "";

        longestHelper(root, ans, "");

        return ans;
    }
};

int main() {

    vector<string> words = {
        "w",
        "wo",
        "wor",
        "worl",
        "world"
    };

    Trie trie;

    for(string word : words) {

        trie.insert(word);
    }

    cout << trie.longestWord();

    return 0;
}

//ANS:=
//world