/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-03 
 * Check if a number is Prime.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(ll int n){
  if(n<=1) return false;
  if(n==2)return true;
  for(int i=2;i<=ceil(sqrt(n));i++) if(n%i==0)return false;
  return true;
}
void solve(){
   int n,cnt=0;
   cin>>n;
   int a[n];
   FOR(i,0,n)a[i]=i+1;
   FOR(i,0,n){
     if(isPrime(a[i]))cout<<a[i]<<" ";
   }
   cout<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
