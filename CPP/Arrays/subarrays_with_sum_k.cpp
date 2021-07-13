/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-13
 * @desc Given an unsorted array of integers, find the number of subarrays having sum exactly equal to a given number k.
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include <bits/stdc++.h>
using namespace std;

int numberOfSubArraysWithSumK(int a[], int n, int k){
    unordered_map<int,int>m;
    int sum=0,cnt=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==k)cnt++;
        if(m[sum-k]){ //There will be a sub array whose sum is k from the index where sum-k is obtained to curr index
            cnt+=m[sum-k];
        }
        m[sum]+=1;
    }
    return cnt;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        cout<<numberOfSubArraysWithSumK(Arr, N, k)<<endl;
    }
    return 0;
} 