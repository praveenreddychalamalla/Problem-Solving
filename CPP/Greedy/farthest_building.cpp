/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-21
 * @desc Leetcode 1642. Furthest Building You Can Reach
 */


#include<bits/stdc++.h>
using namespace std;

//Time Complexity - O(n log k), Space Complexity - O(k). k = # ladders 
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq; //Min Heap
        int n=heights.size(),index=0;
        for(int i=1;i<n;i++){
            int d=heights[i]-heights[i-1];
            if(d>0){
                pq.push(d);
                if(pq.size()>ladders){ //Use ladders for the buildings where heights difference is large
                    bricks-=pq.top(); //Use the bricks for buildings where heights difference is small
                    pq.pop();
                }
                if(bricks<0)break;
            }
            index=i;
        }
        return index;
    }
};