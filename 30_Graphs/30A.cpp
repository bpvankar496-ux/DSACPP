// Question 4: Word Ladder
// Ek word thi bija word sudhi minimum steps — BFS use karo
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    if (wordSet.find(endWord) == wordSet.end()) return 0;

    queue<pair<string,int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (int i = 0; i < word.size(); i++) {
            string temp = word;
            for (char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;
                if (temp == endWord) return steps + 1;
                if (wordSet.find(temp) != wordSet.end()) {
                    wordSet.erase(temp);
                    q.push({temp, steps + 1});
                }
            }
        }
    }
    return 0;
}

int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    // 5
    return 0;
}

//ANS:=
//5