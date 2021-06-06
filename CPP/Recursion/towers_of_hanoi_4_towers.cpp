/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-04 
 * @desc Towers of Hanoi , N discs 4 Towers (A,B,C,D). Move all discs from A to B using C,D.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int cnt;
void TOH(int n, char A, char B, char C,char D ){
  if(n==1) {
    cnt+=1;  //cout<<"Move Discs: "<<A<<"-->"<<B<<endl
    return ;
  }
  if(n==2){
    cnt+=3; //cout<<"Move Discs: "<<A<<"-->"<<C<<", "<<A<<"-->"<<B<<", "<<C<<"-->"<<B<<endl
    return ;
  }
  else{
    TOH(n-2,A,D,B,C);
    cnt+=3; //cout<<"Move Discs: "<<A<<"-->"<<C<<", "<<A<<"-->"<<B<<", "<<C<<"-->"<<B<<endl
    TOH(n-2,D,B,A,C);
  }
}
void solve(){
    ll int n;
    cnt=0;
    cin>>n;
    TOH(n,'A','B','C','D');
    cout<<cnt<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
