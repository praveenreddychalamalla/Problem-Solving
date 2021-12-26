 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-26
 * @desc Alien Dictionary 
 */

//Time Complexity - O(n*|s|*k), Space Complexity - O(k).  k=26
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool visited[26]; //trouble with vector, resize. Check 
    void dfs(char u,stack<char>& st, unordered_map<char,vector<char>>& adj){
        //cout<<u<<endl;
        if(visited[u-'a'])return ;
        visited[u-'a']=true;
        int m=adj[u].size();
        for(int i=0;i<m;i++){
            char v=adj[u][i];
            if(!visited[v])dfs(v,st,adj);
        }
        st.push(u);
    }
    string findOrder(string s[], int N, int K) {
        unordered_map<char,vector<char>>adj;
        for(int i=1;i<N;i++){
            string s1=s[i-1];
            string s2=s[i];
            int j=0;
            while(s1[j]==s2[j])j++; 
            adj[s1[j]].push_back(s2[j]); //add an edge between the alphabets, if the characters differ at j th position in the two strings 
        }
        stack<char>st;
        for(int i=0;i<26;i++)visited[i]=0;
        for(int i=0;i<26;i++){ //get topological order by performing dfs
            
            if(!visited[i])dfs('a'+i,st,adj);
        }
        string res="";
        while(!st.empty()){//topological order
            res+=st.top();
            st.pop();
        }
        return res;
    }
};