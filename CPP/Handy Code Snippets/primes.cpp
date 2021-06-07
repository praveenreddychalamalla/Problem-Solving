/**
  * Author: Praveen Reddy Chalamalla
  * Created on 31-05-2021
  * @desc Generates Primes upto n - Time Complexity = O(n * loglogn) 
  * (1/2 + 1/3+ 1/5+ 1/7+.....)= log log n.
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ll long long

vector<int>primes(ll int n){
  vector<int>v(n+1,1),v2;
  v[0]=0;v[1]=0;
  FOR(i,2,n+1){
    if(v[i]){
      ll int k=2;
      while(i*k<=n){
        v[i*k]=0;
        k++;
      }
    }
  }
  for(int i=0;i<=n;i++)if(v[i])v2.pb(i);
  return v2;
}
int main() {
    ll int n;
    cin>>n;
    vector<int>v=primes(n);
    //for(auto i: v)cout<<i<<" ";
	return 0;
}
