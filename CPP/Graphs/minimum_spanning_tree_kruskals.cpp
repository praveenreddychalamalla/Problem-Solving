 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-04-27
 * @desc LC 1584: Min Cost to Connect All Points. (MST From complete Graph)
 */

//Time Complexity - O(k log n^n) {k= No. of edges to pull for constructing MST. k<< n^n}, Space Complexity - O(n^n)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>parent;
    int find(int x){
        return parent[x]==x?x:parent[x]=find(parent[x]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int cost=0;
        vector<array<int,3>>a;
        parent.resize(n,-1);
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];
                int d=abs(x1-x2)+abs(y1-y2);
                a.push_back({d,i,j});
            }
        }
        make_heap(a.begin(),a.end(),greater<array<int,3>>()); //Transforms the sequence to Min heap
        while(!a.empty()){
            pop_heap(a.begin(),a.end(),greater<array<int,3>>()); //Moves the top element of the heap to last and decreases heap size by 1
            auto [d,x,y]=a.back();
            a.pop_back(); //Pop the last element (Min )
            x=find(x),y=find(y);
            if(x!=y){
                cost+=d;
                parent[y]=x;
            }
        }
        return cost;
    }
    
};