//Longest Word With All Prefixes Present (Trie)

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
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }

    // DFS HELPER
    void longestHelper(Node* root,
                       string &ans,
                       string temp) {

        for(auto child : root->children) {

            char ch = child.first;
            Node* nextNode = child.second;

            // only continue if word exists
            if(nextNode->endOfWord) {

                temp += ch;

                // update answer
                if((temp.size() > ans.size()) ||
                   (temp.size() == ans.size()
                    && temp < ans)) {

                    ans = temp;
                }

                longestHelper(nextNode,
                              ans,
                              temp);

                // backtrack
                temp.pop_back();
            }
        }
    }

    // MAIN FUNCTION
    string longestStringWithEOW() {

        string ans = "";

        longestHelper(root, ans, "");

        return ans;
    }
};

int main() {

    vector<string> words = {
        "a",
        "banana",
        "app",
        "appl",
        "ap",
        "apply",
        "apple"
    };

    Trie trie;

    for(string word : words) {
        trie.insert(word);
    }

    cout << trie.longestStringWithEOW();

    return 0;
}

//ANS:=
//apple
