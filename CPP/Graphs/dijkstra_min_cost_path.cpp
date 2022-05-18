 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-26
 * @desc Given a square grid of size N, each cell of which contains integer cost 
 *       which represents a cost to traverse through that cell, 
 *       we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
 *       From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 
 *       Note: It is assumed that negative cost cycles do not exist in the input matrix.
 */

//Time Complexity - O(n^2 log n), Space Complexity - O(n^2).
#include<bits/stdc++.h>
using namespace std;
class Solution{

    public:
    vector<vector<int>>dist;
    int m,n;
    
    void dijkstra(vector<vector<int>>& grid){

        int m=grid.size(),n=grid[0].size();

        dist[0][0]=grid[0][0];
        set<pair<int,pair<int,int>>>s;
        s.insert({dist[0][0],{0,0}});

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        while(!s.empty()){

            pair<int,pair<int,int>>p=*s.begin();
            s.erase(s.begin());

            int x=p.second.first,y=p.second.second;

            for(int i=0;i<4;i++){ //neighbours of current node - adjacent cells (left right top down)

                int _x=x+dx[i];
                int _y=y+dy[i];
                if(_x<0 ||_y<0 || _x>=m||_y>=n)continue;

                if(dist[_x][_y]>dist[x][y]+grid[_x][_y]){ //Relax the outgoing edges, if cost of any node is decreased ==> erase it from set and insert updated node
                    if(dist[_x][_y]!=INT_MAX) s.erase(s.find({dist[_x][_y],{_x,_y}}));
                    dist[_x][_y]=dist[x][y]+grid[_x][_y];
                    s.insert({dist[_x][_y],{_x,_y}});
                }
            }
        }
    }
    int minimumCostPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dist.resize(m,vector<int>(n,INT_MAX));
        dijkstra(grid);
        
        return dist[m-1][n-1];
    }
};