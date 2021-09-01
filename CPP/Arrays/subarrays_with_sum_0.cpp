/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-01
 * @desc You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.
 */
#include<bits/stdc++.h>
using namespace std;

long long findSubarray(vector<long long> a, int n ) {
    unordered_map<long long,vector<int>>m;
    m[0].push_back(-1); //Already we have empty subarray initially, with sum=0, hence mark its presence
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        m[sum].push_back(i);
    }
    long long cnt=0;
    for(auto e:m){
        long long x=e.second.size();
        if(x>1)cnt+=(x*(x-1))/2;
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
       
        vector<long long> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout << findSubarray(arr,n) << "\n";
    }
	return 0;
}  