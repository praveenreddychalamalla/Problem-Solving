/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-04 
 * @desc Towers of Hanoi , N discs 3 Towers (X,Y,Z). Move all discs from X to Y using Z.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int cnt;
void TOH(int n, char X, char Y, char Z){
  if(n==1) {
    cnt+=1; // //cout<<"Move Disc: "<<X<<"-->"<<Y<<endl
    return ;
  }
  else{
    TOH(n-1,X,Z,Y);
    cnt+=1; //cout<<"Move Disc from "<<X<<"-->"<<Y<<endl
    TOH(n-1,Z,Y,X);
  }
}
void solve(){
    ll int n;
    cnt=0;
    cin>>n;
    TOH(n,'X','Y','Z');
    cout<<cnt<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
