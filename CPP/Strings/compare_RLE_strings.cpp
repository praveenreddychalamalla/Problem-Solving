/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-14
 * @desc Compare 2 Run Length Encoded Strings
 */
#include<bits/stdc++.h>
using namespace std;
string compressString(string& s){
    string temp;
    int cnt=0,val=0;
    char prev='-';
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i])){
            if(s[i]==prev){
                cnt+=val;
                val=0;
            }
            else{
                if(cnt+val)temp+=to_string(cnt+val);
                prev=s[i];
                temp+=s[i];
                cnt=0;
                val=0;
            }
        }
        else{
            val=val*10+s[i]-'0';
        }
    }
    temp+=to_string(cnt+val);
    return temp;
}
int compareRLEStrings(string& s1, string& s2){
  string temp1="",temp2="";
  temp1=compressString(s1);
  temp2=compressString(s2);
  if(temp1==temp2)return 1;
  else return 0;
}
int main() {
  int t;
  cin>>t;
  while(t--){
    string str1,str2;
    cin>>str1>>str2;
    cout<<compareRLEStrings(str1,str2)<<endl;
  }
  return 0;
}
