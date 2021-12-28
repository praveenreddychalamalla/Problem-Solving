/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-28
 * @desc Word Boggle II
 */

#include<bits/stdc++.h> 
using namespace std; 
class Solution {

public:

    struct TrieNode{
        bool flag;
        TrieNode* next[26];
        TrieNode(){
            flag=false;
            for(int i=0;i<26;i++)next[i]=NULL;
        }
    };

    void insertIntoTrie(TrieNode *root, string word){
        int l=word.length();
        for(int i=0;i<l;i++){
            if(!root->next[word[i]-'A'])root->next[word[i]-'A']=new TrieNode();
            root=root->next[word[i]-'A'];
        }
        root->flag=true;//flag=true==> leaf node, end of word
    }

    int checkPrefix(TrieNode *root, string word){
        int l=word.length();
        for(int i=0;i<l;i++){
            if(!root->next[word[i]-'A'])return 0; 
            root=root->next[word[i]-'A'];
        }
        if(root->flag)return 1;
        else return -1;
    }

    unordered_set<string>res;
    vector<vector<bool>>visited;
    vector<int>dx{1,0,-1,0,-1,-1,1,1}, dy{0,1,0,-1,-1,1,1,-1};
    int m,n;

    void dfs(int i, int j, vector<vector<char>>&a,string &word ,TrieNode * root){

        if(i<0 || j<0 ||i>=m|| j>=n ||visited[i][j])return;
  
        visited[i][j]=1;
        word+=a[i][j];
        int x=checkPrefix(root,word); 

        if(x==0){ //If this word doesn't match any prefix of the given words, useless to explore further
            visited[i][j]=0;
            word.pop_back();
            return;
            
        }
        else if(x==1){
            res.insert(word);
        }
        
        for(int k=0;k<8;k++){
            int _x=dx[k]+i, _y=dy[k]+j;
            dfs(_x,_y,a,word,root);
        }
        word.pop_back();
        visited[i][j]=0;
    }
    
	vector<string> wordBoggle(vector<vector<char> >& a, vector<string>& dictionary) {
	   res.clear();
	   visited.clear();
	   m=a.size(),n=a[0].size();
	   visited.resize(m,vector<bool>(n,0));
	   fill(visited.begin(),visited.end(),vector<bool>(n,false));
	   
	   TrieNode * root=new TrieNode();
	   int l=dictionary.size();
	   for(int i=0;i<l;i++)insertIntoTrie(root,dictionary[i]);
	   
	   for(int i=0;i<m;i++){
	       for(int j=0;j<n;j++){
	           
	           string word="";
	           dfs(i,j,a,word,root);
	       }
	   }

	   vector<string>ans;
	   for(auto e:res)ans.push_back(e);
	   return ans;
	}
};