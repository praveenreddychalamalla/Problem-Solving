/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-01
 * @desc Given an array of positive integers. 
 * Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers.
 */

#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O(n), Space Complexity - O(n)
int findLongestConseqSubseq(int a[], int n){
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)m[a[i]]=1;
    int res=1,len=1;
    for(int i=0;i<n;i++){
        if(m[a[i]-1]==0){ //If a[i]-1 doesn't exist, a[i] could be start of some subsequence. Explore the largest subsquence starting with a[i]
            int j=a[i];
            while(m[j])j++;
            res=max(res,j-a[i]);
        }
    }
    return res;
}


/**
 * Time Complexity - O(nlogn), Space Complexity- O(1)
 * 
 * int findLongestConseqSubseq(int a[], int n){
    sort(a,a+n);
    int res=1,len=1;
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]==1){
            len++;
            res=max(res,len);
        }
        else{
            if(a[i]!=a[i-1])len=1;
        }
    }
    return res;
}
*/

int main(){
 int  t,n,i,a[100001];
 cin>>t;
 while(t--){
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
} 