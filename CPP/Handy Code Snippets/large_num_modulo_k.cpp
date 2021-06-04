/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-03 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int mod=1e9+7;

ll int power(ll int a,ll int n){
  if(n==0)return 1;
  int temp=power(a,n/2);
  if(n%2) return (((a*temp)%mod)*temp)%mod;
  else return (temp*temp)%mod;
}
void solve(){
   ll int n,m,p;
   cin>>n>>m;
   cout<<power(n,m)<<endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
    solve();
	return 0;
}
