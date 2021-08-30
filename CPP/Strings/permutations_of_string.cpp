/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-29
 * @desc Given a string S. The task is to print all permutations of a given string
 */

//Time Complexity - O(n!*n), Space Complexity - O(n)

/**
 * Using STL - next_permutation 
    vector<string>find_permutation(string s){
        sort(s.begin(),s.end()); //String sholud be sorted other wise next_permuation cannot yield all permutations
        vector<string>res;
        res.push_back(s);
        while(next_permutation(s.begin(),s.end())) res.push_back(s);
        return res;
    } 
*/
#include<bits/stdc++.h>
using namespace std;
void permute(string s, string ans, vector<string>& res){
    if(s.length()==0){
        res.push_back(ans);
        return ;
    }
    for(int i=0;i<s.length();i++){
        char c=s[i];
        string left=s.substr(0,i);
        string right=s.substr(i+1);
        string temp=left+right;
        permute(temp,ans+c,res);
    }
}
vector<string>find_permutation(string s){
    sort(s.begin(),s.end());
    vector<string>res;
    permute(s,"",res);
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    vector<string> ans = find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}