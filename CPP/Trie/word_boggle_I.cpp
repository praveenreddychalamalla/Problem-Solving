/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-02
 * @desc Given an m x n board of characters and a list of strings words, return all words on the board.
 *       Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
 *       The same letter cell may not be used more than once in a word.
 */



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode{
        char c;
        TrieNode* child[26];
        TrieNode(char ch){
            c=ch;
            for(int i=0;i<26;i++)child[i]=NULL;
        }
    };
    bool searchTrie(TrieNode* root, string &s){
        TrieNode* trav=root;
        for(auto c:s){
            if(!trav->child[c-'a'])return false;
            trav=trav->child[c-'a'];
        }
        return true;
    }
    void insertIntoTrie(TrieNode* root, string&s){
        TrieNode* trav=root;
        for(auto c:s){
            if(!trav->child[c-'a'])trav->child[c-'a']=new TrieNode(c);
            trav=trav->child[c-'a'];
        }
    }
    TrieNode* buildTrie(vector<string>&a){
        TrieNode *root=new TrieNode(' ');
        for(auto s:a){
            insertIntoTrie(root,s);
        }
        return root;
    }
    
    vector<string>res;
    unordered_map<string,int>um;
    TrieNode *root;
    void exploreWords(vector<vector<char>>& a,int i,int j,string& s,vector<vector<bool>> & visited){
        int m=a.size(),n=a[0].size();
        if(i<0||i>=m||j<0||j>=n||visited[i][j]==1)return;
        s+=a[i][j];
        if(!searchTrie(root,s)){ //If the current string does not match with any prefix in trie, waste of exploring further, hence return
            s.pop_back();
            return ;
        }
        visited[i][j]=1;
        if(um.find(s)!=um.end()){
            if(um[s]){
                res.push_back(s);
                um[s]=0;
            }   
        }
        exploreWords(a,i+1,j,s,visited);
        exploreWords(a,i-1,j,s,visited);
        exploreWords(a,i,j+1,s,visited);
        exploreWords(a,i,j-1,s,visited);
        visited[i][j]=0;
        s.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();
        um.clear();
        root =buildTrie(words);
        for(auto s: words) um[s]=1;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<bool>>visited(m,vector<bool>(n,0));
                string s="";
                exploreWords(board,i,j,s,visited);
            }
        }
        return res;
    }
};