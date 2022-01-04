/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-02
 * @desc A company is organizing a meeting and has a list of n employees, waiting to be invited. 
 *       They have arranged for a large circular table, capable of seating any number of employees.The employees are numbered from 0 to n - 1.
 *       Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. 
 *       The favorite person of an employee is not themself.
 * 
 *       Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, 
 *       return the maximum number of employees that can be invited to the meeting.
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;
/**
 * Kosarju + DFS
 * 
 * Case 1: If two nodes are independent (SCC with size 2 i..e., cycle of length 2), we can DFS from these two nodes backwards (Using reversed graph) 
 *         and find the longest of two arms (length a, b) ==> form a free component of a+b+2
 * 
 * Case 2: If there is a cyclic dependency, ans could be length of this cycle (:-
 */
class Solution {
public: 
    
    vector<bool>visited;
    void dfs1(int v, vector<vector<int>>& adj, stack<int>& st){
        if(visited[v])return;
        visited[v]=true;
        for(auto u: adj[v]){
            dfs1(u,adj,st);
        }
        st.push(v);
        return ;
    }
    
    void dfs2(int v, vector<vector<int>>& adj,vector<int> &curr_comp){ //  DFS on Strongly Connected Components in reversed graph
        if(visited[v])return;
        visited[v]=true;
        curr_comp.push_back(v); // store the nodes of current component
        for(auto u:adj[v]){
            dfs2(u,adj,curr_comp);
        }
        return ;
    }
    
    int dfs3(int curr, int next, vector<vector<int>>& adj){ //Extend from the node in the reversed graph.
        int l=0;
        for(auto u: adj[curr]){
            if(u!=next)l=max(l,dfs3(u,curr,adj));
        }
        return l+1;
    }
    
    int maximumInvitations(vector<int>& favourite) {
        
        int n=favourite.size();
        vector<vector<int>>graph(n),rev_graph(n);
        for(int i=0;i<n;i++){
            graph[i].push_back(favourite[i]);
            rev_graph[favourite[i]].push_back(i);
        }
        visited.resize(n);
        fill(visited.begin(),visited.end(),false);
        
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!visited[i])dfs1(i,graph,st);
        }
        
        fill(visited.begin(),visited.end(),false);
        
        int largest_scc=0,groups=0;

        while(!st.empty()){
            int u=st.top();
            st.pop();
            if(!visited[u]){ //A node from one of the SCC got popped out
                vector<int>curr_component;
                dfs2(u,rev_graph,curr_component);

                if(curr_component.size()==2){ //Perform the dfs on the reversed graph from the nodes
                    groups+=dfs3(curr_component[0],curr_component[1],rev_graph); //includes a+1
                    groups+=dfs3(curr_component[1],curr_component[0],rev_graph); //includes b+1 ==>a+b+2
                }
                largest_scc=max(largest_scc,(int)curr_component.size());
            }
        }
        return max(largest_scc, groups);
    }
};