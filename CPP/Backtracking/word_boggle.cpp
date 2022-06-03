/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-03
 * @desc Given an m x n board of characters and a list of strings words, return all words on the board.
 *       Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are any of the 8 neighbours. 
 *       The same letter cell may not be used more than once in a word.
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>dir={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    bool visited[50][50];
    bool dfs(int i, int j, vector<vector<char>>& board, string& s, int k){
        int m=board.size(),n=board[0].size();
        if(k==s.length())return true;
        if(i<0||i>=m||j<0||j>=n || visited[i][j]|| board[i][j]!=s[k])return false;
        visited[i][j]=true;
        for(int d=0;d<8;d++){
             int x=i+dir[d][0],y=j+dir[d][1];
             if(dfs(x,y,board,s,k+1)){
                 visited[i][j]=false; //Unvisit the current cell and return. So that you don't have to reset the visited matrix for every dfs call from searchWord function
                 return true;
             }
        }
        visited[i][j]=false;
        return false;
    }
    bool searchBoard(vector<vector<char>>& board, string& s){ //O(m*n* 7^s). From every cell you can explore in 7 directions except first dfs call
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,board,s,0)) return true;
            }
        }
        return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    memset(visited,0,sizeof(visited)); //Visited vector - TLE
	    vector<string>res;
	    for(auto s: dictionary){
	        if(searchBoard(board,s))res.push_back(s);
	    }
	    return res;
	}
};