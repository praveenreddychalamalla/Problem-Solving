/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-13
 * @desc Egg Dropping Problem.
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][10001];
    int solve(int e, int f){

        if(e==1)return f;
        if(f==0||f==1)return f;

        if(dp[e][f]!=-1)return dp[e][f];

        int min_attempts=INT_MAX;

        int l=1,r=f,temp;

        while(l<=r){

            int mid=(l+r)/2; //Choose mid as kth floor

            int left=solve(e-1,mid-1);  //Egg broke
            int right=solve(e,f-mid);  //Egg didn't break

            temp=1+max(left,right);

            if(left<right)l=mid+1; //If Upper floors requires more attempts, try to reduce the attempts required in the upper floors. This can be done by picking k from the upper floors.
            else r=mid-1; //If lower floor requires more attempts. Move k into lower half space which can reduce the no.of attempts required in lower floors

            min_attempts=min(min_attempts,temp);
        }

        return dp[e][f]= min_attempts;
    }
    int superEggDrop(int e, int f) {
        memset(dp,-1,sizeof(dp));
        return solve(e,f);
    }
};
/**
 * Recursive Approach: Time Complexity - O(n*2^(min(e,f))), Space Complexity - O(max(f,k))
 * 
 * class Solution {
    public:
        int solve(int e, int f){

            if(e==1)return f; //If eggs==1, Only choice is to perform a linear search to find the critical floor (Throw from floor - 1,2,3,...critcal floor (f-worst case))
            
            if(f==0||f==1)return f; // If floors ==0 then we don't require any attempts (No critical floor). If floors ==1 then we need one attempt to decide (Egg breaks? Doesn't break?)

            int min_attempts=INT_MAX;

            //Egg throw from kth floor ==> egg broke --> You will search for critical floor in the lower floors (k-1), egg didn't break --> You will search for critical floor in the upper floors (n-k)
           
            for(int k=1;k<=f;k++){

                int temp=1+max(solve(e-1,k-1),solve(e,f-k)); //You need worst case attempts, hence pick max attempts to decide critical floor from the splitted sub problems

                min_attempts=min(min_attempts,temp);

            }
            return min_attempts;
        }
        int superEggDrop(int e, int f) {
            return solve(e,f);
        }
    };
 * 
 */

/**
 * Top down DP Memoization: Time Complexity - O(n*k * n) = (n^2 * k), Space Complexity O(n*k)
 * 
 * class Solution {
    public:
        int dp[101][10001];
        int solve(int e, int f){

            if(e==1)return f;
            if(f==0||f==1)return f;

            if(dp[e][f]!=-1)return dp[e][f];

            int min_attempts=INT_MAX;
            for(int k=1;k<=f;k++){ //This Linear search can be optimized with binary search
                int temp=1+max(solve(e-1,k-1),solve(e,f-k));
                min_attempts=min(min_attempts,temp);
            }

            return dp[e][f]=min_attempts;
        }
        int superEggDrop(int e, int f) {
            memset(dp,-1,sizeof(dp));
            return solve(e,f);
        }
    };
 *
 */
