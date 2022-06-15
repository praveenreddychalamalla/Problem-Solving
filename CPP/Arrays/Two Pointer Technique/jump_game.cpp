/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-16
 * @desc Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element.
 *       Find the minimum number of jumps to reach the end of the array (starting from the first element). 
 *       If an element is 0, then you cannot move through that element.
 *       Note: Return -1 if you can't reach the end of the array.
 */

#include<bits/stdc++.h>
using namespace std;

//Time Complexity - O(n), Space Complexity - O(1)
class Solution{
  public:
    int minJumps(int a[], int n){
        if(n==1)return 0;
        int limit=0,range=0,jumps=0;
        for(int i=0;i<n;i++){

            range=max(range,i+a[i]); //Update the farthest index you can reach while sliding through the accessible window. 

            //If you hit the limit, the window in your hand gets exhausted. 
            //You cannot move further unless you choose to jump from some index in the slided window. Update the limit
            if(limit==i){
                limit=range;
                jumps++;
                if(limit>=n-1)break; //End of array is reached.
                if(limit==i)return -1; //Stuck at index i, cannot move further
            }
        }
        return jumps;
    }
};