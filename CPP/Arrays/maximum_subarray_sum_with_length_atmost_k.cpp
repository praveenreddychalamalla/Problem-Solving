/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-15
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

int maxSum1(int a[], int p[],int n,int k){
  int res=0;
  for(int i=0;i<n;i++){
    for(int j=i;j<i+k && j<n;j++){
      res=max(p[j]-p[i],res);
      //cout<<res<<" ";
    }
  }
  return res;
}

int maxSum2(int a[], int p[], int n,int k){
    deque<int>dq;
    int res=0;
    for(int i=0;i<n;i++){
      while(!dq.empty() && p[i]<p[dq.back()])dq.pop_back();
      dq.push_back(i);
      if(dq.back()-dq.front()>k)dq.pop_front();
      res=max(p[dq.back()]-p[dq.front()],res);
    }
    return res;
}
void solve(){
    int n=9;
    int a[n]={3,-5,1,2,-10,40,2,1,-2};
    int prefix[n]={a[0]};
    for(int i=1;i<n;i++)prefix[i]=a[i]+prefix[i-1];
    for(int i=0;i<n;i++)cout<<prefix[i]<<" ";
    cout<<endl;
    cout<<maxSum1(a,prefix,9,9)<<endl;
    cout<<maxSum2(a,prefix,9,9)<<endl;

}
 
int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int t=1;
  //cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
