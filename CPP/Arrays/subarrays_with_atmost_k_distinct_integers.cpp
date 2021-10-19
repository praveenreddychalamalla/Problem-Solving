/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-10-18
 * @desc You are given an array arr[] of size n and an integer K. Count the number of subarrays that have at most ‘K’ distinct values.
 * Variant : Count Subarrays that have exactly K distinct integers ==> exactly(K) = atMost(K) - atMost(K-1)
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;

int kDistinctSubarrays(vector<int> &a, int n, int k){
    unordered_map<int,int> m;
    int j=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        m[a[i]]++;
        while(m.size()>k){
            m[a[j]]--;
            if(m[a[j]]==0)m.erase(a[j]);
            j++;
        }
        cnt+=i-j+1; 
        /* a=[1,1,2,3] , k=2 ; 
         * Window : [1] => 1 subarray 
         * Window : [1,1] => 2 subarrays ([1],[1,1] -  Prefix for new integer added (1))
         * Window : [1,1,2] => 3 subarrays ([2],[1,2],[1,1,2] - Prefix for new integer added (2)) 
         * Window : [1,1,2,3] ==> [2,3]  => 2 subarrays ([3],[2,3] - Prefix for new integer added (3))
         * Each time after you add an integer to existing window, subarrays resulted newly = length of window remaing after consolidation as per constraint.
        */
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
       
        vector<int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout << kDistinctSubarrays(arr,n,k)<< "\n";
    }
	return 0;
}  

