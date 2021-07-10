/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-10
 * @desc Generates first n odd length palindrome numbers
 */
#include<bits/stdc++.h>
using namespace std;
vector<long long int> oddLengthPalindromeNumbers(int n){
    vector<long long int>v;
    int k=1;
    long long int x=10;
    for(int i=1;i<10;i++) v.push_back(i);
    if(n<10) {
        v.resize(n);
        return v;
    }
    while(v.size()<n){
        string s1=to_string(x),s2=s1.substr(0,k);
        reverse(s2.begin(),s2.end());
        for(int i=0;i<10;i++){
            v.push_back(stoll(s1.substr(0,k)+to_string(i)+s2));
        }
        x+=10;
        if(x!=10 && int(log10(x))==log10(x))k++;
    }
    return v;
}

int main() {
  int n;
  cin>>n;
  vector<long long int> v=oddLengthPalindromeNumbers(n);
  for(auto i:v)cout<<i<<" ";
  return 0;
}
