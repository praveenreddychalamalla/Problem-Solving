/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-09
 * @desc Given a binary circular array nums,
 *       return the minimum number of swaps required to group all 1's present in the array together at any location.
 */

//Time Complexity - O(n), Space Complexity - O(1) 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++)if(nums[i]==1)x++; //Count no.of ones. All the 1's will fit into a subarray of size x
        int res=INT_MAX,i=0,j=0,cnt=0;
        while(i<x){
           if(nums[i]==1)cnt++; 
           i++;
        }
        i=i%n; //[1] ==> after the above while loop, i=1 (Index out of bounds)
        while(j<n){ //slide through every window of size x, No of swaps required = No.of zeroes in the current subarray
            res=min(res,x-cnt);
            if(nums[j++]==1)cnt--;
            if(nums[i]==1)cnt++;
            i=(i+1)%n;
        }
        return res;
    }
};