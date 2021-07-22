/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-22 
 * @desc Binary Exponentiation - a^n : Iterative Approach 
*/

//Time Complexity - O(log n), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Iterative Approach
ll int power(ll int a,ll int n){
  ll ans=1;
  while(n){
      if(n%2)ans=ans*a;
      a=a*a;
      n>>=1;
  }
  return ans;
}

int main() {
    
  int t;
  cin>>t;
  while(t--){
        ll int a,n;
        cin>>a>>n;
        cout<<power(a,n)<<endl;
  }
  return 0;
}
