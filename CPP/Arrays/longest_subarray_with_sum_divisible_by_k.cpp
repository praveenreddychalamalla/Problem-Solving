/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-01
 * @desc Given an array containing N integers and a positive integer K,
 *       find the length of the longest sub array with sum of the elements divisible by the given value K.
 */

//Time complexity - O(n), Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int longSubarrWthSumDivByK(int a[], int n, int k){
    long long sum=0;
    unordered_map<int,pair<int,int>>m;
    m[0]={-1,-1};
    int res=0;
    for(int i=0;i<n;i++){ 
        sum=(((sum+a[i])%k)+k)%k; //Array may contain negative elements also, hence take the mod twice.
        if(m.find(sum)==m.end())m[sum]={i,i};
        else m[sum].second=i;
    }
    for(auto e:m){
        res=max(res,e.second.second-e.second.first);
    }
    return res;
}

int main(){
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	cout<<longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}