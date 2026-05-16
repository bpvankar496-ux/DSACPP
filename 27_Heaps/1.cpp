// For index i:
// Left child  → 2*i + 1
// Right child → 2*i + 2
// Parent      → (i-1)/2

// A heap is a complete binary tree that follows a specific rule called the heap property.
// 1. Max Heap
// Parent node is greater than its children
// 2. Min Heap
// Parent node is smaller than its children

//PQ in C++==>prioraty  Queue

#include <bits/stdc++.h>
using namespace std;

int main() {

    //  1. Integer - Max Heap (Descending)
   
    priority_queue<int> maxPQ;

    maxPQ.push(5);
    maxPQ.push(10);
    maxPQ.push(9);
    maxPQ.push(7);
    maxPQ.push(3);

    cout << "Integer Max Heap (Descending): ";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }
    cout << endl;


  
    //  2. Integer - Min Heap (Ascending)
  
    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(5);
    minPQ.push(10);
    minPQ.push(9);
    minPQ.push(7);
    minPQ.push(3);

    cout << "Integer Min Heap (Ascending): ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << endl;


    //  3. String - Max Heap (Descending)
    priority_queue<string> maxStrPQ;

    maxStrPQ.push("helloworld");
    maxStrPQ.push("apnacollege");
    maxStrPQ.push("c++");
    maxStrPQ.push("alpha");

    cout << "String Max Heap (Descending): ";
    while (!maxStrPQ.empty()) {
        cout << maxStrPQ.top() << " ";
        maxStrPQ.pop();
    }
    cout << endl;



    //  4. String - Min Heap (Ascending)
    
    priority_queue<string, vector<string>, greater<string>> minStrPQ;

    minStrPQ.push("helloworld");
    minStrPQ.push("apnacollege");
    minStrPQ.push("c++");
    minStrPQ.push("alpha");

    cout << "String Min Heap (Ascending): ";
    while (!minStrPQ.empty()) {
        cout << minStrPQ.top() << " ";
        minStrPQ.pop();
    }
    cout << endl;

    return 0;
}

// ANS:=
// Integer Max Heap (Descending): 10 9 7 5 3 
// Integer Min Heap (Ascending): 3 5 7 9 10 
// String Max Heap (Descending): helloworld c++ apnacollege alpha 
// String Min Heap (Ascending): alpha apnacollege c++ helloworld 