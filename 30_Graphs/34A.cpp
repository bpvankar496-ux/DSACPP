// Question 8: Alien Dictionary
// Words thi alien language no order find karo — Topological Sort
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;

    for (auto word : words)
        for (char c : word)
            indegree[c] = 0;

    for (int i = 0; i < words.size()-1; i++) {
        string w1 = words[i], w2 = words[i+1];
        int len = min(w1.size(), w2.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                found = true;
                break;
            }
        }
        if (!found && w1.size() > w2.size()) return "";
    }

    queue<char> q;
    for (auto p : indegree)
        if (p.second == 0) q.push(p.first);

    string result = "";
    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        result += curr;

        for (char v : adj[curr]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    return result.size() == indegree.size() ? result : "";
}

int main() {
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    cout << alienOrder(words) << endl;
    // wertf
    return 0;
}

//ANS:=
//wertf