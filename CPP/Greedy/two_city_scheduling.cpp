/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-05-11
 * @desc Leetcode 1029 : https://leetcode.com/problems/two-city-scheduling/
 */

//Time Complexity - O(n log n), Space Complexity - O(1) 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& a) {
        int n=a.size(),cost=0;
        //Sort by savings. How much would you save by sending a person to City A in contrast to sending the same person to City B
        sort(a.begin(),a.end(),[&](vector<int>v1,vector<int>v2){ return v1[1]-v1[0]>v2[1]-v2[0];});
        for(int i=0;i<n/2;i++){
            cost+=a[i][0]+a[n-i-1][1];
        }
        return cost;
    }
};