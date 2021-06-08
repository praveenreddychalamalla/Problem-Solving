/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-08 
 * @desc Given a String find the length of longest proper prefix which is also a proper suffix.
 */
#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(n).
int longestPrefixSuffix(string s)
	{
	    int len=0,i=1,n=s.size();
	    int lps[n];
	    lps[0]=0;
	    while(i<n){
	        if(s[len]==s[i]){
	            len++;
	            lps[i]=len;
	            i++;
	        }
	        else{
	            if(len!=0)len=lps[len-1]; //Check this out
	            else{
	                lps[i]=0;
	                i++;
	            }
	        }
	    }
	    return lps[n-1];
	}
int main() {
  
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    cout<<longestPrefixSuffix(s)<<endl;
  }
  return 0;
}
