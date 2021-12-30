/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-30
 * @desc Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k,
 *       and n only contains the digit 1. Return the length of n. If there is no such n, return -1.
 */

//Time Complexity - O(k), Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) { //k=3 ==> n=111, length =3
        unordered_map<int,int>m;
        long long n=0;
        int res=-1,cnt=0;
        //Nnext % K = (Nprev * 10 + 1) % K = ( (Nprev * 10) % K + 1 % K) % K = ( (Nprev % K * 10) % K + 1) % K
        while(true){
            n=(n*10)%k+1; //1,11,111,1111,11111.....
            cnt++;
            if(n%k==0){
                res=cnt;
                break;
            }
            if(m.find(n%k)!=m.end()) break; //If you hit any existing remainders, same cycle continues and hence you cannot obtain remainder 0
            else m[n%k]=1;
            n=n%k;
        }
        return res;
    }
};