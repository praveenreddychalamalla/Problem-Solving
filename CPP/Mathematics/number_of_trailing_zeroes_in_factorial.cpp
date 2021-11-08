#include <bits/stdc++.h>
using namespace std;
void solve(){
   long long int n,cnt=0;
   cin>>n;
   for(int i=5;n/i>=1;i*=5) // Trailing 0s in n! = Count of 5s in prime factors of n!= floor(n/5) + floor(n/25) + floor(n/125) + ....
       cnt+=floor(n/i);
   cout<<cnt<<endl;
}
int main() {
    int t,n;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
