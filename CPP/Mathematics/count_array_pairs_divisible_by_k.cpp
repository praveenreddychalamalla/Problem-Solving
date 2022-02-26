/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-02-24
 * @desc Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) 
 *       such that: 0 <= i < j <= n - 1 and nums[i] * nums[j] is divisible by k. 
 */

//Time Complexity - O(n * log n), Space Complexity - O(log n) {For recursion}


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countPairs(vector<int>& a, int k) {
        int n=a.size();
        unordered_map<long long,long long>gcds;
        long long cnt=0;
        // (a*b)%k = 0 <==> (gcd(a,k) * gcd(b,k))%k = 0 ==> gcd(b,k) = n * (k/gcd(a,k)) <==> gcd(b,k) % (k/gcd(a,k)) = 0
        for(int i=0;i<n;i++){
            long long gcd1=__gcd(a[i],k), gcd2=k/gcd1; 
            if(gcd2==1)cnt+=i; //a[i] can pair up with any number before it. (stored gcd1 will serve other numbers after i) 
            else {
              for(auto e:gcds){
                  if(e.first%gcd2==0)cnt+=e.second;
              }  
            } 
            gcds[gcd1]++;
        }
        return cnt;
    }
};