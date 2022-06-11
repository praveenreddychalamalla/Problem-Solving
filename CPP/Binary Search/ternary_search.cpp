/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-08
 * @desc Ternary Search
 */

#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(log n), Space Complexity - O(1).
class Solution{
    public:
    int ternarySearch(int a[], int n, int k) 
    { 
       int l=0,r=n-1;
       while(l<=r){
           int m1=l+(r-l)/3,m2=r-(r-l)/3 ;
           if(a[m1]==k)return 1;
           if(a[m2]==k)return 1;
           if(k<a[m1])r=m1-1;
           else if(k<a[m2]){
               l=m1+1;
               r=m2-1;
           }
           else l=m2+1;
       }
       return -1;
    }
};
