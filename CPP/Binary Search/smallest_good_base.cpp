/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-04
 * @desc Given an integer n represented as a string, return the smallest good base of n.
 *       We call k >= 2 a good base of n, if all digits of n base k are 1's.
 *       n is an integer in the range [3, 10^18]. n does not contain any leading zeros.
 */

//Time Complexity - O(log n), Space Complexity - O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unsigned long long int goodBase(int n, unsigned long long int x){ //n=length of 1's
        //left limit for binary search of base l =1, and right limit r = x^(1/n)+1 { 1+b+b^2+..b^n=x ==> b^n<=x ==> b <=x^(1/n)+1 }
        unsigned long long int l=1,r=(unsigned long long)(pow(x,1.0/n)+1); 
        while(l<=r){
            unsigned long long int mid=(l+r)/2,d=1,s=1;
            for(int i=0;i<n;i++){
                d*=mid;
                s+=d;
                if(s>x)break;
            }
            if(s==x)return mid;
            else if(s<x)l=mid+1; //With mid as base and n 1's, number obtained < X ==> Increase the base => Get into right half space
            else r=mid-1;
        }
        return 0; //No base fits into n 1's to produce x
    }
    string smallestGoodBase(string s) {
        unsigned long long int n=(unsigned long long int)stoll(s),x=1;
        for(int i=62;i>=1;i--){//Smallest base==>More No.of 1's
            if((x<<i)<n){ //If 2^i >=n you cannot fit any extra 1's in i bits to produce n
                unsigned long long int b=goodBase(i,n); //Check if you can produce 'n' with 'i' 1's and some base
                if(b) return to_string(b);
            }
        }
        return to_string(n-1);
    }
};