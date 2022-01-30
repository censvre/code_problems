#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
 
// Data structure to store a min-heap node
struct PriorityQueue
{
private:
    // vector to store heap elements
    vector<int> heap;
 
    // return parent of `heap[i]` which is (index - 1) / 2
    // don't call this function if `index` is already a root node
    int parent(int index) {
        return (index - 1) / 2;
    }
 
    // return left child of `heap[index]`
    int left(int index) {
        return (2*index + 1);
    }
 
    // return right child of `heap[index]`
    int right(int index) {
        return (2*index + 2);
    }
 
    // Recursive heapify-down algorithm.
    void heapify_down(int index)
    {
        // get left and right child of node at index `index`
        int left = left(index);
        int right = right(index);
 
        int smallest = index;
 
        // compare `heap[index]` with its left and right child
        // and find the smallest value
        if (left < size() && heap[left] < heap[index]) {
            smallest = left;
        }
 
        if (right < size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
 
        // swap with a child having lesser value and call heapify down
        if (smallest != index)
        {
            swap(heap[i], heap[smallest]);
            heapify_down(smallest);
        }
    }
 
    // Recursive heapify-up algorithm
    void heapify_up(int index)
    {
        // check if the node at index `index` and its parent violate the heap property
        if (index && heap[parent(i)] > heap[index])
        {
            // swap the two if heap property is violated
            swap(heap[index], heap[parent(i)]);
 
            // call heapify-up on the parent
            heapify_up(parent(index));
        }
    }
 
public:
    // return size of the heap
    unsigned int size() {
        return heap.size();
    }
 
    // Function to check if the heap is empty or not
    bool empty() {
        return size() == 0;
    }
 
    // insert key into the heap
    void push(int key)
    {
        // insert a new element at the end of the vector
        heap.push_back(key);
 
        // get element index and call heapify-up procedure
        int index = (size() - 1);
        heapify_up(index);
    }
 
    // Function to remove an element with the lowest priority (present at the root)
    void pop()
    {
        if (size != 0) {
            heap[0] = heap.back();
            heap.pop_back();
 
            // call heapify-down on the root node
            heapify_down(0);
        }
    }
 
    // Function to return an element with the lowest priority (present at the root)
    int top()
    {
        if (size != 0) {
            return heap.at(0); 
        }
        else {
            cout << "Heap has no elements";
        }
};