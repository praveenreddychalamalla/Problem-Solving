
/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-30
 * @desc Given two strings. The task is to find the length of the longest common substring.
 */
#include<bits/stdc++.h>
using namespace std;

//Time Complexity - O(n log m) (Average Case), Space Complexity - O(m)
unordered_map<int,vector<int>>mp; 

void computeHashValues(string& s,int n,int l){ //Compute the hash values for every substring of length l in string s

	int p=1e9+7,b=26,q=1;
	int i=0,win_hash=0;

	for(;i<l;i++){
		win_hash=(win_hash*b+s[i]-'a')%p;
		q=(q*b)%p;
	}

	mp[win_hash].push_back(i-l);
	while(i<n){
		win_hash=(win_hash*b+(s[i]-'a') - (s[i-l]-'a')*q)%p;
		i++;
		if(win_hash<0)win_hash+=p;
		mp[win_hash].push_back(i-l);
	}

	return ;
	
}

bool matchStrings(string &s1, int i,string &s2, int l, vector<int>& v){
	for(auto j: v){
		if(s1.substr(i,l)==s2.substr(j,l))return true;
	}
	return false;
}

bool findSubString(string &s1, string &s2,int n, int m, int l){

	int p=1e9+7,b=26,q=1;
	int i=0,win_hash=0;

	for(;i<l;i++){
		win_hash=(win_hash*b+s1[i]-'a')%p;
		q=(q*b)%p;
	}

	while(i<n){
		if(mp.find(win_hash)!=mp.end()){ //If there is a substring with same hashvalue in the hash table, compare the strings for equality
			if(matchStrings(s1,i-l,s2,l,mp[win_hash]))return true;
		}
		win_hash=(win_hash*b+(s1[i]-'a') - (s1[i-l]-'a')*q)%p;
		i++;
		if(win_hash<0)win_hash+=p;
	}
	if(mp.find(win_hash)!=mp.end()){
		if(matchStrings(s1,i-l,s2,l,mp[win_hash]))return true;
	}

	return false;
}

int longestCommonSubstr (string s1, string s2, int n, int m){

	if(n<m)return longestCommonSubstr(s2,s1,m,n);

	transform(s1.begin(),s1.end(),s1.begin(),::tolower);
	transform(s2.begin(),s2.end(),s2.begin(),::tolower);

	int l=0,r=m,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		mp.clear();
		computeHashValues(s2,m,mid); //O(m) 
		bool ans=findSubString(s1,s2,n,m,mid); //O(n) - Average Case
		if(ans){
			l=mid+1;
			res=mid;
		}
		else r=mid-1;
	}

	return res;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;

        cout << longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
