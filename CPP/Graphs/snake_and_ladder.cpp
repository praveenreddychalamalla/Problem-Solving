 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-26
 * @desc Given a 5x6 snakes and ladders board, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from the source (1st cell).
 *      You are given an integer N denoting the total number of snakes and ladders and an array arr[] of 2*N size where 2*i and (2*i + 1)th values denote the starting and ending point respectively of ith snake or ladder. The board looks like the following.
 */

//Time Complexity - O(N), Space Complexity - O(N)
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minThrow(int N, int arr[]){
        queue<pair<int,int>>q;
        vector<int>move(31,-1);
        for(int i=0;i<2*N;i+=2){
            move[arr[i]]=arr[i+1];
        }
        q.push({1,0});
        vector<bool>visited(31,0);
        visited[1]=1;
        int dist=INT_MAX;
        while(!q.empty()){
            int n=q.size();
            while(n--){ //Not required - As we are already storing level in pair<>
                pair<int,int>p=q.front();
                q.pop();
                int x=p.first;
                if(x==30){
                    dist=min(dist,p.second);
                } 
                for(int i=x+1;i<=x+6 && i<31;i++){
                    int y=i;
                    if(move[i]!=-1)y=move[i];
                    if(!visited[y]){
                        visited[y]=true;
                        q.push({y,p.second+1});
                    }
                }
            }
            
        }
        return dist;
    }
};