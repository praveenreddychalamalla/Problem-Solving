/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-08
 * @desc Skyline Problem.  Reference : https://leetcode.com/problems/the-skyline-problem/
 */
#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(nlogn), Space Complexity - O(n) 

struct point{
    int x;
    int y;
    int flag;
    point(int a,int b, char c){
        x=a;
        y=b;
        flag=c;
    }
};

class Solution {
public:
    static bool comp(const point&a,const point&b){
         return a.x==b.x?(a.y==b.y?a.flag<b.flag:a.y<b.y):a.x<b.x;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>res;
        vector<point>a;
        for(auto v:buildings){
            a.push_back(point{v[0],v[2],0}); //0 indicates the start of building with x1,h
            a.push_back(point{v[1],v[2],1}); //1 indicates the start of building with x2,h
        }
        sort(a.begin(),a.end(),comp);
        map<int,int>m; //Insert heights of bulidings.We need taller buliding height at every instance
        m[0]=1;
        int max_h=0;
        for(auto e:a){
            if(e.flag==1){
                m[e.y]--;
                if(m[e.y]==0)m.erase(e.y);
            }
            else{
                m[e.y]++;
            }
            auto h=m.rbegin()->first;
            if(h!=max_h){ //New Buling height overshadows or taller building passed its end
                max_h=h;
                int n=res.size();
                if(n>0 && res[n-1][0]==e.x){ //Check if prev interval is at same x coordinate
                    res[n-1][1]=max(res[n-1][1],max_h);
                }
                else res.push_back(vector<int>{e.x,max_h});
            }
        }
        return res;
    }
};