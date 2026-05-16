//13. Stock Span Problem
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void stockSpan(vector<int> stock) {
    stack<int> s;
    vector<int> span(stock.size());

    s.push(0);
    span[0] = 1;

    for(int i = 1; i < stock.size(); i++) {
        while(!s.empty() && stock[i] >= stock[s.top()]) {
            s.pop();
        }

        if(s.empty()) span[i] = i + 1;
        else span[i] = i - s.top();

        s.push(i);
    }

    for(int x : span) cout << x << " ";
}

int main() {
    vector<int> stock = {100,80,60,70,60,85,100};
    stockSpan(stock);
}

//ANS:=
//1 1 1 2 1 5 7 