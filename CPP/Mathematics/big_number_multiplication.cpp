/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-21
 * @desc Given two numbers as stings s1 and s2. Calculate their Product
 */

//Time Complexity - O(n1*n2), Space Complexity - O(n1+n2)
#include<bits/stdc++.h>
using namespace std;
 
string multiplyStrings(string s1, string s2) {
    int l1=s1.length(),l2=s2.length(),sign1=1,sign2=1;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    if(s1[l1-1]=='-'){
        sign1=-1;
        l1--;
    }
    if(s2[l2-1]=='-'){
        sign2=-1;
        l2--;
    }
    int n=l1+l2;
    vector<int>res(n,0);

    for(int i=0;i<l1;i++){
        int x=i,carry=0;
        for(int j=0;j<l2;j++){
            int prod=(s1[i]-'0')*(s2[j]-'0')+carry;
            int sum=res[x]+prod;
            res[x++]=sum%10;
            carry=sum/10;
        }
        res[x]+=carry;
    }
    string s="";
    int i=n-1;
    while(i>=0 && res[i]==0)i--; //Ignore Leading Zeroes
    if(i>=0){
        if(sign1*sign2==-1)s+='-';
    }
    while(i>=0)s+=to_string(res[i--]);
    return s!=""?s:"0";
}

 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	cout<<multiplyStrings(a,b)<<endl;
    }
     
} 