/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-10-19
 * @desc The distance of a pair of integers a and b is defined as the absolute difference between a and b.
 *       Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] 
 *       where 0 <= i < j < nums.length.
 */

//Time Complexity - O(n * log n * log range) {range = largest dist - smallest dist in array}, Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

/*int countPairs(vector<int>&a, int x){ //O(n^2)
    int n=a.size(),cnt=0;
    for(int i=0;i<n;i++){
        int j=i+1;
        while(j<n && a[j]-a[i]<=x)j++;
        cnt+=j-i-1;
    }
    return cnt;
}*/
int countPairs(vector<int>&a, int x){ //No.of pairs with distance<=m . O(n*log n)  
    int n=a.size(),cnt=0;
    for(int i=0;i<n;i++){
        auto it=upper_bound(a.begin(),a.end(),a[i]+x);
        cnt+=(it-a.begin())-i-1;
    }
    return cnt;
}
int smallestDistancePair(vector<int>& a, int k) {
    int n=a.size();
    sort(a.begin(),a.end());
    int l=INT_MAX,r=a[n-1]-a[0];
    for(int i=1;i<n;i++)l=min(l,a[i]-a[i-1]);
    
    while(l<r){
        int m=(l+r)/2;
        if(countPairs(a,m)<k)l=m+1;  //If no.of pairs with distance <=m are less than k ==> kth smallest distance lies in right half space [m+1,r]
        else r=m;
    }
    return l;
}
int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int k;
        cin >> k;
        
        cout << smallestDistancePair(vec,k) << "\n";
         
    }
}
