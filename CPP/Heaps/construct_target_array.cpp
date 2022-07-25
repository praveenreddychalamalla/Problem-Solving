/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-24
 * @desc Leetcode : 1354. Construct Target Array With Multiple Sums
 */
#include <bits/stdc++.h>
using namespace std;
class Solution { //Time Complexity - O(n log n), Space Complexity - O(n)
public:
    bool isPossible(vector<int>& target) {
        //Similar to reaching points question. Think this as n dimensional coordinates for it
        priority_queue<int,vector<int>>pq;
        long long s=0;
        for(auto e:target){
            pq.push(e);
            s+=e;
        }
        while(pq.top()>1){
            int curr=pq.top();
            pq.pop();
            if(curr==s)return false;
            int prev=(curr-1)%(s-curr)+1;
            if(prev==curr)return false;
            s=s-(curr-prev);
            pq.push(prev);
        }
        return true;
    }
};