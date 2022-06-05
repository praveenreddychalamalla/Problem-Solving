/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-05
 * @desc Heap Sort
 */

#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(n log n), Space Complexity - O(log n). Space can be brought down to O(1) by writing iterative heapify function
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int a[], int n, int i)  {
        int l=2*i+1,r=2*i+2;
        if(l<n||r<n){ 
            int k=getMaxIndex(a,i,l,r,n);
            if(k==i)return; //The node can't be sent further down in the path
            else swap(a[i],a[k]);
            heapify(a,n,k);
        }
    }

    public:
    //Function to build a Heap from array.
    int getMaxIndex(int a[], int i, int l ,int r,int n){ 
        int k=i;
        if(l<n)k=a[k]<a[l]?l:k;
        if(r<n)k=a[k]<a[r]?r:k;
        return k;
    }

    void buildHeap(int a[], int n)  { 
        for(int i=n-1;i>=0;i--){ //Start building heap from bottom
            int l=2*i+1,r=2*i+2;
            int k=getMaxIndex(a,i,l,r,n); //Get the index of largest element in root, root's left child and root's right child
            swap(a[i],a[k]);
            heapify(a,n,k); //The altered child may go to leaf node in the path. Heapify on the altered child
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int a[], int n)
    {
        buildHeap(a,n);
        for(int i=n-1;i>0;i--){
            swap(a[i],a[0]);
            heapify(a,i,0);
        }
    }
};