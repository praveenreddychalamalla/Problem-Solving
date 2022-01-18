/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-15
 * @desc You are given a 0-indexed binary string s and two integers minJump and maxJump. 
 *       In the beginning, you are standing at index 0, which is equal to '0'. 
 *       You can move from index i to index j if the following conditions are fulfilled: s[j]=='0' &&  i+minJump<= j <=i+maxJump
 *       Return true if you can reach index s.length - 1 in s, or false otherwise.
 */
#include<bits/stdc++.h>
using namespace std;

/**
 * Time Complexity - O(n^2), Space Complexity - O(n)
 * 
 * class Solution {
    public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();

        vector<int>visited(n,0);
        visited[0]=1;

        for(int i=0;i<n;i++){
            if(s[i]=='0' && visited[i]==1){
                for(int j=i+minJump;j<=min(i+maxJump,n-1);j++){  //Slide through the valid range and mark reachable positions
                    if(s[j]=='0')visited[j]=1;
                }
            }
        }
        return visited[n-1];
        
    }
 };
 * 
 * Here we might slide through the same range many times, and end up doing only some work.
 * Eg : "00.........." , min=1, max=1000. 
 *       From index 0 : The range [1,1000] will be covered and all indices with s[i]=='0 will be marked as visited
 *       From index 1 : The range [2,1001] will be covered. You will slide through entire range and end up marking only 1 index as visited in best case i.e., if s[1001]=='0'
 *                      The range [2,1000] is already covered and the valid positions are already marked visited.
 *       Hence its redundant to slide through covered range. We just need to cover only the new range i.e., [1001,1001]
 *       
 *       Instead of sliding the window from i+min everytime, remember the last covered range and pick the max(last covered range, i+min). 
 */

//Time Complexity - O(n), Space Complexity - O(n) {Can be brought down to O(1), instead of using visited array, chane char at visited index to '2'}
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        vector<int>visited(n,0);
        visited[0]=1;
        int j=0; //Store the covered range so far
        for(int i=0;i<n;i++){
            if(s[i]=='0' && visited[i]==1){
                for(j=max(j,i+minJump);j<=min(i+maxJump,n-1);j++){
                    if(s[j]=='0')visited[j]=1;
                }
            }
        }
        return visited[n-1];
        
    }
};