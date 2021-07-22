/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-22
 * @desc Binary Exponentiation - a^n : Recursive Approach 
*/

//Time Complexity - O(log n), Space Complexity - O(log n)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Recursive Approach
ll int power(ll int a,ll int n){
  if(n==0)return 1;
  ll int x=power(a,n/2);
  if(n%2)return a*x*x;
  else return x*x;
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
