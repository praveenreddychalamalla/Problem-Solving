/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-12
 * @desc  Rearrange the given array in-place such that all the negative numbers occur before positive numbers by maintaining the relative order
 */
#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(n logn), Space Complexity - O(log n).
void merge(int a[], int l, int m, int r){
    int i=l,j=m+1;
    while(i<=m && a[i]<0)i++;
    while(j<=r && a[j]<0)j++;
    reverse(a+i,a+m+1);
    reverse(a+m+1,a+j);
    reverse(a+i,a+j);
    return;
}
void rearrangePosNegElements(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        rearrangePosNegElements(a,l,m);
        rearrangePosNegElements(a,m+1,r);
        merge(a,l,m,r);
    }
}
void Rearrange(int a[], int n)
{
    rearrangePosNegElements(a,0,n-1);
}