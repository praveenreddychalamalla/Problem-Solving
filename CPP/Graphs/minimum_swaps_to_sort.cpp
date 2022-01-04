#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>>a;
	    int n=nums.size();
	    for(int i=0;i<n;i++)a.push_back({nums[i],i});
	    sort(a.begin(),a.end());
	    vector<bool>visited(n,false);
	    int swaps=0;
	    for(int i=0;i<n;i++){
	        if(a[i].second==i || visited[i])continue;
	        int j=i;
	        int cycle_length=0;
	        while(!visited[j]){
	            visited[j]=true;
	            j=a[j].second;
	            cycle_length++;
	        }
	        if(cycle_length)swaps+=cycle_length-1;
	    }
	    return swaps;
	}
};