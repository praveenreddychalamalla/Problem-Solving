/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-10-19
 * @desc You are given an integer array nums and you have to return a new counts array. 
 *       The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
 */

//Time Complexity - O(n log n), Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;

void merge(vector<pair<int,int>>&a, int l, int m, int r, vector<int>&res){
    int i=l,j=m+1,k=0;
    vector<pair<int,int>>temp(r-l+1);
    int cnt=0;
    while(i<=m && j<=r){
        if(a[i].first>a[j].first){ //Instead of updating count for every number after a[i] in left subarray - preserve the count and update once
            cnt++;
            temp[k++]=a[j++];
        }
        else{
            res[a[i].second]+=cnt; //Update the count in result array with the help of original index
            temp[k++]=a[i++];
        }
    }
    while(i<=m){
        res[a[i].second]+=cnt;
        temp[k++]=a[i++];
    }
    while(j<=r)temp[k++]=a[j++];
    k=0;
    for(int i=l;i<=r;i++)a[i]=temp[k++];
}
void mergeSort(vector<pair<int,int>>&a, int l, int r, vector<int>&res){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m,res);
        mergeSort(a,m+1,r,res);
        merge(a,l,m,r,res);
    }
}
vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    vector<int>res(n,0);
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++)a.push_back({nums[i],i}); //Store number and it's original index
    mergeSort(a,0,n-1,res);
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) 
            cin >> arr[i];
        vector<int> ans = countSmaller(arr);
        for(auto count : ans)cout<<count<<" ";
        cout <<"\n";
    }
    return 0;
} 