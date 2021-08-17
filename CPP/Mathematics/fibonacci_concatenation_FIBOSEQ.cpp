/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-15
 * @desc Application on Fermats Little Theorem
 * Let's define Fibonacci concatenation sequence as follows:
 *
 * f[0]=0, f[1]=1
 * f[i]=f[i−1]+f[i−2], for every i≥2
 * Here f[i] denotes the ith Fibonacci concatenation number and + represents concatenation.
 *
 * For example, f[2]=f[1]+f[0]=1+0=10, f[3]=f[2]+f[1]= 10+1= 101.
 *
 * Given an integer n, you have to determine the sum of digits of all subsequences of the nth Fibonacci concatenation number f[n], modulo 109+7
 */
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pi pair<int,int>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(V) (V).begin(), (V).end() 
#define ll long long
#define endl '\n'
using namespace std;
long long  mod=1e9+7;
long long power(long long a,long long n){
    if(n==0)return 1;
    long long x=power(a,n/2);
    if(n%2)return (((x*x)%mod)*(a%mod))%mod;
    else return (x*x)%mod;
}
vector<long long>f(100001,0);
vector<long long>l(100001,0);
void solve(){
    int n;
    cin>>n;
    if(n==1||n==2){
      if(n==1)cout<<1<<endl;
      else cout<<2<<endl;
      return;
    }
    //Fermats little Theroem
    long long x=(l[n]*power(2,mod-2))%mod; // we need (l[n]/2))%mod ==> (l[n]*2^(mod-2))%mod
    long long res=(f[n]*x)%mod;
    cout<<res<<endl;
}
 
 
int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int t;
  f[0]=0;f[1]=1;
  l[0]=2;l[1]=2;
  FOR(i,2,100001){
    f[i]=(f[i-1]+f[i-2])%mod;
    l[i]=(l[i-1]*l[i-2])%mod;
  }
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
