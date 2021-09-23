/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-22
 * @desc Given two strings A and B, 
 * find the minimum number of times A has to be repeated such that B becomes a substring of the repeated A.
 * If B cannot be a substring of A no matter how many times it is repeated, return -1.
 */

//Time Complexity - O(n^2), Space Complexity - O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string&s, int n){
    vector<int>LPS(n,0);
    int i=1,len=0;
    while(i<n){
        if(s[len]==s[i]){
            LPS[i]=len+1;
            i++;
            len++;
        }
        else{
            if(len!=0)len=LPS[len-1];
            else{
                LPS[i]=0;
                i++;
            }
        }
    }
    return LPS;
}
int checkSubString(string&s1, string&s2,vector<int>& LPS){
    int n=s1.length(),m=s2.length();
    int i=0,j=0;
    while(i<n){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        else{
            if(j!=0)j=LPS[j-1];
            else i++;
        }
        if(j==m)return 1;
    }
    return 0;
}
int repeatedStringMatch(string s1, string s2) {
    int cnt=0,n=s1.length(),m=s2.length(),l=0;
    string s="";
    vector<int>LPS=computeLPS(s2,m);
    while(l<=2*m){
        cnt++;
        s+=s1;
        l+=n;
        if(checkSubString(s,s2,LPS))return cnt; //KMP - Linear Time
    }
    return -1;
    
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        cout<<repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}