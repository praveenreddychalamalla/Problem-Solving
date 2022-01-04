/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-01
 * @desc A gallery with plants is divided into n parts, numbered : 0,1,2,3...n-1. 
 *      There are provisions for attaching water sprinklers at every partition. 
 *      A sprinkler with range x at partition i can water all partitions from i-x to i+x.
 * 
 *      Given an array gallery[ ] consisting of n integers, where gallery[i] is the range of sprinkler at partition i (power==-1 indicates no sprinkler attached), 
 *      return the minimum number of sprinklers that need to be turned on to water the complete gallery.
 *      If there is no possible way to water the full length using the given sprinklers, print -1.
 */

//Time Complexity - O(nlogn), Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:

    static bool comp(pair<int,int>& a, pair<int,int>&b){
        return a.first==b.first?a.second<b.second:a.first<b.first;
    }

    int min_sprinklers(int a[], int n){
        vector<pair<int,int>>v;//Form the intervals of each sprinkler, for the range  which it can cover.
        for(int i=0;i<n;i++){
            if(a[i]!=-1)v.push_back({max(0,i-a[i]),min(n-1,i+a[i])}); 
        }
        
        if(v.empty())return -1;
        
        sort(v.begin(),v.end(),comp); //sort the intervals. 
        
       
    
        int i=0,cnt=0,curr_right=0, max_right=0;
        int N=v.size();
        while(max_right<n-1){
            if(i>=N || curr_right<v[i].first)return -1; //i>=N ==> intervals are completed but still all partitions (n [0,n-1]) are not covered

             //Pick the sprinkler which can cover the largest range (maximum right) and overlaps with the current range (start<=curr_end) (:-
            while(i<N && v[i].first<=curr_right)max_right=max(max_right,v[i++].second); 
            cnt++;
            curr_right=max_right+1; // The picked sprinkler can cover upto max_right (inclusive), hence you can pick the intervals whose start <= max_right+1 (curr_right for the next iteration)
            //Eg: [0,10],[11,15]             
        }
        return cnt;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}
