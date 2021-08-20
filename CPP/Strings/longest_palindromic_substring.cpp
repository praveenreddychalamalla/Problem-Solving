/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-19
 * @desc Given a string S, find the longest palindromic substring in S. 
 * Note : In case of multiple answers, return the substring with least starting index.
 */

//Time Complexity - O(n^2), Space complexity - O(n^2) {n=|s|}
#include<bits/stdc++.h> 
using namespace std; 
/**
 * s[i:j] is a substring, if s[i]==s[j] and s[i+1:j-1] is a palindrome i.e., 
 * If starting and ending characters are same and non boundary substring is a palindrome. 
 * check if s[i+1:j-1] is a palindrome from earlier computed results i.e.., dp {Used for computing 3 length strings onwards}
*/
string longestPalindrome(string s){
    int n=s.length(),l=1,start=0,end=0; //l stores the length of longest palindrome obtained so far, start and end store the indices of same
    string res="";
    res+=s[0];
    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        dp[i][i]=1; // All one length characters are palindromes, hence fill 1's in the principle diagonal of dp
        if(s[i]==s[i-1]){ //Check for 2 length palindromes 
            dp[i-1][i]=1; //Fill dp[i-1][i] with 1, if string starting at i-1 and ending at i, is a palindrome.
            if(l==1){ //Update the result if any.
                l=2;
                start=i-1;
                end=i;
            }
        }
        else dp[i-1][i]=0;
    }
    for(int k=2;k<n;k++){
        for(int i=0,j=k;i<n-k;j++,i++){ //i points to start index and j points to end index
            if(s[i]==s[j] && dp[i+1][j-1]==1){// if s[i]==s[j] and s[i+1:j-1] is a palindrome, s[i:j] is a palindrome
                dp[i][j]=1; //Indicates that s[i:j] is a palindrome.
                if(j-i+1>l){ //Update if there is any better result.
                    l=j-i+1;
                    start=i;
                    end=j;
                }
            }
            else dp[i][j]=0;
        }
    }
    return s.substr(start,l);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        cout<<longestPalindrome(S)<<endl;
    }
    return 0;
}