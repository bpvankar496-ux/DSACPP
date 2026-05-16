#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> arr;

public:
    //  PUSH (Insert)
    void push(int val) {
        arr.push_back(val);              // add at end
        int i = arr.size() - 1;

        // Heapify UP
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    //  POP (Delete root)
    void pop() {
        if (arr.size() == 0) return;

        // Step 1: replace root with last element
        arr[0] = arr.back();
        arr.pop_back();

        // Step 2: Heapify DOWN
        int i = 0;
        int n = arr.size();

        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if (left < n && arr[left] > arr[largest])
                largest = left;

            if (right < n && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    // Top element
    int top() {
        if (arr.size() == 0) return -1;
        return arr[0];
    }

    // Print heap
    void print() {
        for (int x : arr) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    // PUSH
    h.push(10);
    h.push(5);
    h.push(20);
    h.push(2);
    h.push(15);

    cout << "Heap after push: ";
    h.print();

    // POP
    h.pop();
    cout << "After 1st pop: ";
    h.print();

    h.pop();
    cout << "After 2nd pop: ";
    h.print();

    return 0;
}

// ANS:=
// Heap after push: 20 15 10 2 5 
// After 1st pop: 15 5 10 2 
// After 2nd pop: 10 5 2 