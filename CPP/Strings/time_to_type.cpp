/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-14
 * @desc Time to Type. Keyboard ASCII Character set 256
 */
#include<bits/stdc++.h>
using namespace std;
int timeToType(string keyboard, string text){
    int pos[256]={0},time=0;
    for(int i=0;i<keyboard.length();i++){
        pos[keyboard[i]]=i; //inverted indexing
    }
    for(int i=1;i<text.length();i++){
        time+=abs(pos[text[i]]-pos[text[i-1]]);
    }
    return time;
}
int main() {
  int t;
  cin>>t;
  while(t--){
    string keyboard,text;
    cin>>keyboard>>text;
    cout<<timeToType(keyboard,text)<<endl;
  }
  return 0;
}
