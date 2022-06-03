/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-02 
 * @desc String Permutations
 */
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void generatePermutations(string s, int i, int n, vector<string>&res){
        if(i==n){
            res.push_back(s);
            return ;
        }
        for(int j=i;j<n;j++){
            swap(s[i],s[j]);
            generatePermutations(s,i+1,n,res); //Fix s[0:i] and explore by swapping remaining positions
            swap(s[i],s[j]);
        }
    }
    vector<string> permute(string s){
       sort(s.begin(),s.end());
       vector<string>res;
       generatePermutations(s,0,s.length(),res);
       return res;
    }
};