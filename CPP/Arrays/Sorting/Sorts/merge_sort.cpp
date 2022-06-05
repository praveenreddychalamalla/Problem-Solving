/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-05
 * @desc Merge Sort
 */

#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(n log n), Space Complexity - O(n)
class Solution
{
    public:
    void merge(int a[], int l, int m, int r)
    {
         vector<int>temp;
         int i=l,j=m+1;
         while(i<=m && j<=r){
             if(a[i]<=a[j]){
                 temp.push_back(a[i++]);
             }
             else temp.push_back(a[j++]);
         }
         while(i<=m)temp.push_back(a[i++]);
         while(j<=r)temp.push_back(a[j++]);
         for(int i=l,k=0;i<=r;i++,k++)a[i]=temp[k];
    }
    public:
    void mergeSort(int a[], int l, int r)
    {
        if(l<r){
            int m=(l+r)/2;
            mergeSort(a,l,m);
            mergeSort(a,m+1,r);
            merge(a,l,m,r);
        }
    }
};