/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-30
 * @desc You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.
 *       You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. 
 *       The probability of picking an index i is w[i] / sum(w).
 */

//Time Complexity - O(n) (log n for each pick index call), Space Complexity - O(1) 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int>prefix_sum;
    Solution(vector<int>& w) {
        n=w.size();
        prefix_sum.resize(n,0);
        prefix_sum[0]=w[0];
        for(int i=1;i<n;i++)prefix_sum[i]=prefix_sum[i-1]+w[i];
    }
    /* w=[1,2,3] ; 0--1----3-------6 : Representing the weight probabilities on number line . 
     * Any number picked from bucket (0,1] should give index 0, from bucket (1,3] should give index 1, from bucket(3,6] should give index 2
     * Perform binary search on prefix sum [1,3,6] (:-
    */ 
    int pickIndex() {
        int x=rand()%prefix_sum[n-1]+1;
        int l=0,r=n-1;
        //return lower_bound(prefix_sum.begin(),prefix_sum.end(),x)-prefix_sum.begin();
        while(l<r){
            int m=(l+r)/2;
            if(prefix_sum[m]>=x)r=m;
            else l=m+1;
        }
        return r;
    }
};