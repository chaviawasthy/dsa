#include<bits/stdc++.h>
using namespace std;

class Heap {
public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity){
        this->arr = new int[capacity + 1]; // Increase capacity by 1 for 1-indexed array
        this->capacity = capacity;
        this->size = 1; // Start size from 1
    }

    void insert(int val){
        if(size > capacity){ // Check if size exceeds capacity
            cout<<"Heap is full"<<endl;
            return;
        }
        int index = size;
        arr[index] = val;
        size++;

        // Take the val to its correct position
        while (index > 1) {
            int parentIndex = index / 2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void deleteMax(){
        if(size == 1){
            cout<<"Heap is empty"<<endl;
            return;
        }
        arr[1] = arr[size - 1];
        size--;

        int index = 1;
        while (index < size) {
            int leftChildIndex = 2 * index;
            int rightChildIndex = 2 * index + 1;
            int largestIndex = index;

            if(leftChildIndex < size && arr[leftChildIndex] > arr[largestIndex]){
                largestIndex = leftChildIndex;
            }
            if(rightChildIndex < size && arr[rightChildIndex] > arr[largestIndex]){
                largestIndex = rightChildIndex;
            }

            if(largestIndex == index){
                break;
            }
            swap(arr[index], arr[largestIndex]);
            index = largestIndex;
        }
    }
};

void heapify(int *arr, int n, int index){
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;

    //take the largest element to the top
    if(leftIndex < n && arr[leftIndex] > arr[largestIndex]){
        largestIndex = leftIndex;
    }
    if(rightIndex < n && arr[rightIndex] > arr[largestIndex]){
        largestIndex = rightIndex;
    }
    // If largest element is not the root
    if(largestIndex != index){
        swap(arr[index], arr[largestIndex]);
        index = largestIndex;
        heapify(arr, n, largestIndex);
    }

    return;
}

void buildHeap(int *arr, int n){
    for(int i=n/2; i>=1; i--){
        heapify(arr, n, i);
    }
}

void heapSort(int *arr, int n){
    buildHeap(arr, n);
    for(int i=n; i>=1; i--){
        swap(arr[1], arr[i]);
        heapify(arr, i, 1);
    }
}

int main(){
    Heap h(20);
    // Insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout<<"Printing the content of heap: "<<endl;
    for(int i=1; i<h.size; i++){ // Iterate up to h.size
        cout<<h.arr[i]<<" ";
    }

    // Deletion
    h.deleteMax();
    cout<<endl<<"Printing the content of heap after deletion: "<<endl;
    for(int i=1; i<h.size; i++){ // Iterate up to h.size
        cout<<h.arr[i]<<" ";
    }

    // Heapify
    int arr[] = {10, 20, 5, 11, 6};
    int n = 5;
    for(int i=n/2; i>=1; i--){
        heapify(arr, n, i);
    }

    cout<<endl<<"Printing the content of heap after heapify: "<<endl;
    for(int i=1; i<=n; i++){ // Iterate up to n
        cout<<arr[i]<<" ";
    }

    // Build Heap
    int arr1[] = {10, 20, 5, 11, 6};
    int n1 = 5;
    buildHeap(arr1, n1);

    // Heap Sort
    int arr2[] = {0, 10, 20, 5, 11, 6};
    int n2 = 5;
    heapSort(arr2, n2);

    cout<<endl<<"Printing the content of heap after heap sort: "<<endl;
    for(int i=1; i<=n2; i++){ // Iterate up to n2
        cout<<arr2[i]<<" ";
    }

    

    return 0;
}
