/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-30
 * @desc A positive integer is magical if it is divisible by either a or b.
 *       Given the three integers n, a, and b, return the nth magical number. 
 *       Since the answer may be very large, return it modulo 109 + 7.
 */

//Time Complexity - O(log(min(a,b))), Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcm(int a, int b){
        return (a*b)/__gcd(a,b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        int x=lcm(a,b),p=1e9+7;
        long long l=min(a,b),r=((long long)n)*min(a,b),res;
        while(l<=r){
            long long mid=(l+r)/2;
            //(mid/a)=No. of multiples of 'a' from l to mid, (mid/b)=No. of multiples of 'b' from l to mid , (mid/x)=No.of multiles of both a,b (lcm of a,b)
            int y=(mid/a)+(mid/b)-(mid/x); //No.of magical numbers from l to mid. 
            if(y<n)l=mid+1;
            else {
                res=mid%p;
                r=mid-1;
            }
        }
        return res;
    }
};