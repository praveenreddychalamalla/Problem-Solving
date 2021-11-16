/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-09
 * @desc SubMask enumeration
 */
#include<bits/stdc++.h>
using namespace std;

//Time Complexity - O(2^x-1). X=No.of set bits in n. Reference : https://cp-algorithms.com/algebra/all-submasks.html
vector<int> subMasks(int n){
   int s=n;
   vector<int>res;
    while(s>0){
        res.push_back(s);
        s=(s-1)&n;
    }
    return res;
}

int main()
{
	 int t;
	 cin>>t;
	 while(t--)
	 {
	       int n;
	       cin>>n;
	       auto res=subMasks(n);
           for(auto x:res)cout<<x<<" ";
           cout<<endl;
	  }
	  return 0;
}