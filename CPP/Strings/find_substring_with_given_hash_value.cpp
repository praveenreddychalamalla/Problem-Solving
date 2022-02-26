/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-30
 * @desc The hash of a 0-indexed string s of length k, given integers p and m, is computed using the following function:
 *       hash(s, p, m) = (val(s[0]) * p0 + val(s[1]) * p1 + ... + val(s[k-1]) * pk-1) mod m.
 *       Where val(s[i]) represents the index of s[i] in the alphabet from val('a') = 1 to val('z') = 26.
 *       You are given a string s and the integers power, modulo, k, and hashValue. Return sub, the first substring of s of length k such that hash(sub, power, modulo) == hashValue.
 */

//Time Complexity - O(n log p) {Can be improved to O(n)}, Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod;
    
    int power(long long a, int n){
        if(n==0)return 1;
        long long x=power(a,n/2);
        if(n%2)return (a*((x*x)%mod))%mod;
        else return (x*x)%mod;
    }
    
    int computeHash(long long a,int x,int n){
        long long b=power(x,n);
        return (a*b)%mod;
    }
    
    string subStrHash(string s, int p, int modulo, int k, int hashValue) {
        long long hash=0;
        mod=modulo;
        int n=s.length();
        int i=n-1;
        //slide window from right to left. So that you can get hash value of current window in O(1). 
        //Subtract s[k]*p^k-1 from hashval, multiply hashval by p so that power of p for every val rises by 1, add new val. 
        for(;i>=n-k;i--){
            long long val=computeHash(s[i]-'a'+1,p,i-(n-k));
            hash=(val+hash)%mod;
        }
        string ans="";
        if(hash==hashValue)ans= s.substr(i+1,k);
        
        for(;i>=0;i--){
            long long val2=computeHash(s[i+k]-'a'+1,p,k-1);
            hash-=val2;
            if(hash<0)hash+=mod;
            
            hash=(hash*p)%mod;
            
            long long val1=s[i]-'a'+1;
            hash=(hash+val1)%mod;
    
            if(hash==hashValue){
                ans=s.substr(i,k);
            }
        }
        return ans;
    }
};