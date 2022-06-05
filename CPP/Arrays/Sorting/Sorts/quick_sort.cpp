/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-05
 * @desc Quick Sort
 */

#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(n log n), Space Complexity - O(n). Amortized costs
class Solution
{
    public:
    void quickSort(int a[], int l, int r)
    {
        if(l<r){
            int p=partition(a,l,r);
            quickSort(a,l,p-1);
            quickSort(a,p+1,r);
        }
    }
    
    public:
    int partition (int a[], int l, int r)
    {
       int i=l,j=r;//You need two pointers.
       while(i<j){
           if(a[i]>a[r]) swap(a[i],a[--j]);
           else i++;
       }
       swap(a[i],a[r]);
       return i;
    }
};
