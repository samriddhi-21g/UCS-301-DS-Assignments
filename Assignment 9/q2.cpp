#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap; // the heap array (0-based indexing)

    // Helper function to move a node up (after insertion)
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Helper function to move a node down (after deletion)
    void heapifyDown(int index) {
        int n = heap.size();
        int largest = index;

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else break;
        }
    }

public:
    // Insert a new value
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Return the maximum element
    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Remove the maximum element
    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Check if empty
    bool empty() {
        return heap.empty();
    }

    // Display all elements (for understanding)
    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(50);

    cout << "Heap elements (internal structure): ";
    pq.display();

    cout << "Maximum element: " << pq.top() << endl;

    pq.pop(); // remove max
    cout << "After deleting max, new max: " << pq.top() << endl;

    cout << "Current heap: ";
    pq.display();

    return 0;
}