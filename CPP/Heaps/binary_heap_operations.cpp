/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-08
 * @desc Binary Heap Operations
 */

#include <bits/stdc++.h>
using namespace std;
struct MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    // Constructor for Min Heap
    MinHeap(int c) {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int); 
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

int getSmallest(int a[], int i, int n){
    int l=2*i+1,r=2*i+2;
    int k=i;
    if(l<n)k=a[k]>a[l]?l:k;
    if(r<n)k=a[k]>a[r]?r:k;
    return k;
}

int MinHeap::extractMin() {
    if(heap_size==0)return -1;
    swap(harr[heap_size-1],harr[0]);
    heap_size--;
    MinHeapify(0);
    return harr[heap_size];
}

void MinHeap::deleteKey(int i){  //Use Decrease Key and Extract Min operations
    if(i>=heap_size)return;
    decreaseKey(i,INT_MIN);
    extractMin();
}


void MinHeap::insertKey(int k) {  //Use Decrease Key operation.
    heap_size++;
    harr[heap_size-1]=INT_MAX;
    decreaseKey(heap_size-1,k);
}


void MinHeap::decreaseKey(int i, int new_val) {   
    harr[i]=new_val;
    int j=parent(i);
    while(harr[j]>harr[i]){
        swap(harr[j],harr[i]);
        i=j;
        j=parent(i);
    }
}

void MinHeap::MinHeapify(int i) {
    int k=getSmallest(harr, i, heap_size);
    if(i==k)return;
    swap(harr[i],harr[k]);
    MinHeapify(k);
}