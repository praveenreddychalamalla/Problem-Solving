/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-12
 * @desc Given a non -Ve integer n, for every number i in the range 0<=i<=n, calculate the no.of 1's in their binary representation and return them as an array
 */
#include<bits/stdc++.h>
using namespace std;


/**
 * Time Complexity - O(n), Space Complexity -O(n).
 * Key Observation : For any two numbers x,y if x/2=y (Integer division), then no.of set bits in x,y will differ by atmost 1.
 * x/2 is same as x>>1, LSB slips, hence no.of set bits either remain same (if x is even, LSB=0, slips and does effect set bits) or decrease by 1 (if x is odd, LSB =1, slips and set bits decrease by 1)
*/
vector<int> countSetBits(int n)
{
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        if(i%2)dp[i]=dp[i/2]+1; //If i is odd, no.of set bits in i=no.of set bits in i/2 +1
        else dp[i]=dp[i/2];
    }
    return dp;
}


int main()
{
	 int t;
	 cin>>t;
	 while(t--)
	 {
	       int n;
	       cin>>n; 
           vector<int>res=countSetBits(n);
	       for(auto e:res)cout<<e<<" ";
           cout<< endl;
	  }
	  return 0;
}
 