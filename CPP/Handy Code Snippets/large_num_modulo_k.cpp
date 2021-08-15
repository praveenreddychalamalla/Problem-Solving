/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-03 
*/
#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
long long power(long long a,long long n){
    if(n==0)return 1;
    long long x=power(a,n/2);
    if(n%2)return (((x*x)%mod)*(a%mod))%mod;
    else return (x*x)%mod;
}
void solve(){
   long long  n,m,p;
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
