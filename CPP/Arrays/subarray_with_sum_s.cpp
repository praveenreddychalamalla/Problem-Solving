/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-15
 * @desc Given an unsorted array A of size N that contains only non-negative integers, 
 *       find a continuous sub-array which adds to a given number S. Return -1 if no such subarray is found
 */

//Time Complexity - O(n), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int a[], int n, int s){
    int i=0,sum=0; //i points to left boundary of current subarray
    vector<int>v;
    for(int j=0;j<n;j++){ //j points to right boundary of current subarray
        sum+=a[j];
        if(sum>s){ //If current subarray sum exceeds s, release elements from left and shrink subarray.
            while(i<j && sum>s){
                sum-=a[i++];
            }
        }
        if(sum==s){
            v.push_back(i+1);
            v.push_back(j+1);
            return v;
        }
    }
    v.push_back(-1);
    return v;
}


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        vector<int>res;
        res = subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
} 