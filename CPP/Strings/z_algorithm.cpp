/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-08
 * @desc Given two strings, one is a text string, txt and other is a pattern string, pat. 
 * The task is to print the indexes of all the occurences of pattern string in the text string. 
 * For printing, Starting Index of a string should be taken as 1.
 */

//Time Complexity - O(m+n), Space Complexity - O(m+n). n=|text|, m=|pattern|
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        vector<int> computeZArray(string &s){
            int n=s.length();
            vector<int>z(n,0);
            int l=0,r=0,i=0,cnt=0;
            for(int i=1;i<n;i++){
                if(r<i){
                    l=r=i;
                    while(r<n && s[r]==s[r-l])r++; 
                    z[i]=r-l;
                    r--;
                }
                else{ //Compute z values in the box [l,r]
                    int k=i-l;
                    if(z[k]+i<=r)z[i]=z[k]; //If z[k]+i does not cross the bound (r)
                    else{
                        l=i; 
                        while(r<n && s[r]==s[r-l])r++;
                        z[i]=r-l;
                        r--;
                    }
                }
            }
            return z;
        }
        vector <int> search(string pat, string txt){
            string s=pat+'$'+txt;
            int m=pat.length(),n=s.length();
            vector<int>z=computeZArray(s);
            vector<int>res;
            for(int i=0;i<n;i++){
                if(z[i]==m)res.push_back(i-m);
            }
            return res;
        }
     
};