
#include<bits/stdc++.h>
using namespace std;
static int dp[2][151][151];
int solve(string &s, int i, int j, int res){
    if(i>j)return 0;
    if(i==j){
        if(s[i]=='T' && res==1 || s[i]=='F' && res==0)return 1;
        else return 0;
    }
    if(dp[res][i][j]!=-1)return dp[res][i][j];
    int cnt=0;
    for(int k=i+1;k<j;k+=2){
        int temp;
        if(s[k]=='&'){
            if(res==1){
                temp=solve(s,i,k-1,1)*solve(s,k+1,j,1);
            }
            else{
                temp=solve(s,i,k-1,1)*solve(s,k+1,j,0) +solve(s,i,k-1,0)*solve(s,k+1,j,1)+ solve(s,i,k-1,0)*solve(s,k+1,j,0);
            }
        }
        else if(s[k]=='|'){
            if(res==1){
                temp=solve(s,i,k-1,1)*solve(s,k+1,j,0) +solve(s,i,k-1,0)*solve(s,k+1,j,1)+ solve(s,i,k-1,1)*solve(s,k+1,j,1);
            }
            else{
                temp=solve(s,i,k-1,0)*solve(s,k+1,j,0);
            }
        }
        else if(s[k]=='^'){
            if(res==1)temp=solve(s,i,k-1,1)*solve(s,k+1,j,0) +solve(s,i,k-1,0)*solve(s,k+1,j,1);
            else temp=solve(s,i,k-1,0)*solve(s,k+1,j,0) +solve(s,i,k-1,1)*solve(s,k+1,j,1);
        }
        cnt=(cnt+(temp)%1003)%1003;
        //cout<<cnt<<endl;
    }
   // cout<<cnt<<endl;
    return dp[res][i][j]=cnt;
}
int cnttrue(string A) {
    memset(dp,-1,sizeof(dp));
    int n=A.length();
    return solve(A,0,n-1,1);
}

 int main(){
     string s;
     cin>>s;
     cout<<cnttrue(s);
 }
