/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-23
 * @desc Disjoint Set Data Structure
 */
#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
vector<int>findRank;
int find(int x){
    if(parent[x]==x)return x;
    else return parent[x]=find(parent[x]);
}
void unionFind(int x,int y){
    int _x=find(x);
    int _y=find(y);
    if(_x==_y)return;
    if(findRank[_x]<findRank[_y]){
        parent[_x]=_y;
    }
    else if(findRank[_x]>findRank[_y]){
        parent[_y]=_x;
    }
    else{
        parent[_y]=_x;
        findRank[_x]++;
    }
}
int main(){

}