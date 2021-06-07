/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-07 
 * @Given a string S,|S|<=1000, Find MEX of string S. 
 * MEX of string is defined as the shortest string that doesn't appear as a contiguous substring in 'S'.
 * If multiple strings exist, the lexicographically smallest one is considered the MEX. null string is not valid mex
 */
#include<bits/stdc++.h>
using namespace std;
// Brute Force - Constructive Algorithm
string MEX(string s){
    int i=0;
    string res="",a="abcdefghijklmnopqrstuvwxyz";
    queue<string>q;
    q.push("");
    while(res==""||s.find(res)!=string::npos){ //find returns npos, if no instance of passed string is found in S
        res=q.front()+a[i++];
        i=i%26;
        if(i==0)q.pop();
        q.push(res);
    }
    return res;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<MEX(s)<<endl;
    }
    return 0;
}
