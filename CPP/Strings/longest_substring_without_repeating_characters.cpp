/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-01
 * @desc Given a string S, find the length of the longest substring without repeating characters.
 */
#include<bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string s){
    vector<int>v(26,-1);
    int res=0,l=0;
    for(int i=0;i<s.length();i++){ //Window - [l,i] : l points to left boundary , i points to right boundary
        if(v[s[i]-'a']>=l){ //If the current character's another presence is within the window, shift the right boundary next to it.
            l=v[s[i]-'a']+1;
        }
        v[s[i]-'a']=i;
        res=max(res,i-l+1);
    }
    return res;
    
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;

		cout<<longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  