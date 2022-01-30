#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
 
// Data structure to store a max-heap node
struct PriorityQueue
{
private:
    // vector to store heap elements
    vector<int> heap;
 
    // return parent of `heap[index]` which is equal to (index - 1) / 2
    // don't call this function if `index` is already a root node
    int parent(int index) {
        return (index - 1) / 2;
    }
 
    // return left child of `heap[index]` which is equal to (2*index + 1)
    int left(int index) {
        return (2*index + 1);
    }
 
    // return right child of `heap[index]` which is equal to (2*index + 2)
    int right(int index) {
        return (2*index + 2);
    }
 
    // Recursive heapify-down algorithm.
    void heapify_down(int index)
    {
        // get left and right child at index
        int left = left(index);
        int right = right(index);
 
        int largest = index;
 
        // compare `heap[index]` with its left and right child, find largest value
        if (left < size() && heap[left] > heap[index]) {
            largest = left;
        }
 
        if (right < size() && A[right] > A[largest]) {
            largest = right;
        }
 
        // recursively call heapify down if the largest element is not the index
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapify_down(largest);
        }
    }
 
    // Recursive heapify-up algorithm
    void heapify_up(int index)
    {
        // check if the node at index and parent violate heapify 
        if (index && heap[parent(index)] < heap[index])
        {
            // swap the two if heap property is violated
            swap(heap[index], heap[parent(index)]);
 
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
        A.push_back(key);
 
        // get element index (last slot in heap)
        int index = (size() - 1);
        // perform heapify up on the index
        heapify_up(index);
    }
 
    // Function to remove an element with the highest priority (present at the root)
    void pop()
    {
        if (size() != 0) {
            A[0] = A.back();
            A.pop_back();
            // call heapify down
            heapify_down(0);
        }
    }
 
    // Function to return an element with the highest priority (present at the root)
    int top()
    {
        if (size() != 0) {
            return heap.at(0); 
        }
        else {
            cout << "Heap has no elements";
        }
};
