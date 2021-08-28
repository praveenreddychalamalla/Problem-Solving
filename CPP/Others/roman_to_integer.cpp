/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-27
 * @desc Given a string in roman no format (s) your task is to convert it to an integer. 1<=roman no range<=3999
 */
#include <bits/stdc++.h>
using namespace std;
int romanToDecimal(string &s) {
    unordered_map<char,int>m;
    m['I']=1;m['V']=5;m['X']=10;m['L']=50;m['C']=100;m['D']=500;m['M']=1000;
    int n=s.length(),res=0;
    for(int i=0;i<n;i++){
        if(i+1<n && m[s[i]]<m[s[i+1]]){
            res+=m[s[i+1]]-m[s[i]]; //XL=40 i.e., L-X ; CM=900 i.e., M-C
            i+=1;
        }
        else res+=m[s[i]];
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}  