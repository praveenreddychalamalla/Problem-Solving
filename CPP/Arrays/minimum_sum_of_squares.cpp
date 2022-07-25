/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-07-09
 * @desc Given an array and k, find the min sum of squares of each element. 0<= a[i] <=1e5
 *       You can decrement any element by 1 in one operation. No.of operations cannot exceed k.
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * Optimal Conversion: Always try to bring down larger squares 
 * Eg - [7,6,4,4,4,3] ==> [6,6,4,4,4,3] ==>[4,4,4,4,4,3]==> [3,3,3,3,3,3] ==> [0,0,0,0,0,0]
 * k=2, [4,4,4,3] ==> [4,3,3,3] {Cannot convert all 4's to 3}
 */
class Solution {
public:
    long long minSumSquares(vector<int>& a,int k) {
        int n=a.size();
        map<int,int>m;
        m[0]=1;
        for(int i=0;i<n;i++)m[a[i]]++;
        while(k){
            auto e1=m.rbegin();
            int x=e1->first,cnt=e1->second;
            if(x==0)break;
            m.erase(x);
            auto e2=m.rbegin();
            int y=e2->first,d=x-y; //d is the cost to bring each x to y
            if(d*cnt<=k){ //Use k operations to convert all x's to y's if possible
                k-=d*cnt;
                m[y]+=cnt;
            }
            else{
                int q=k/cnt,r=k%cnt; //Calculate how much you can bring down each x close to y => r x's can be decremented by q+1, remaining can be decremented by q
                m[x-q]+=(cnt-r);
                m[x-(q+1)]+=r;
                k=0;
            }
        }
        long long res=0;
        for(auto e:m){
            long long x=e.first,y=e.second;
            res+=(x*x)*y;
        }
        return res;
    }
};