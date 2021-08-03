/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-02
 * @desc Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. 
 *       In case there are multiple such windows of same length, return the one with the least starting index. 
 */

//Time Complexity - O(n), Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

string smallestWindow (string s, string p){

    int m1[256]={0},m2[256]={0}; //Frequency Maps. m1 for string p, m2 for current window in string s
    int l=-1,r=-1;
    for(char c:p)m1[c]++;
    int n=p.length();
    int cnt=0,j=0; //cnt keeps track of characters matched with those of string p, j - left index of current window
    for(int i=0;i<s.length();i++){
        m2[s[i]]++;
        if(m1[s[i]]&&m2[s[i]]<=m1[s[i]]){ //If character is present in string s and its count in current window is less than required
            cnt++; //Increment characters matched
        }
        if(cnt==n){
            if(l==-1 && r==-1){
                l=j;
                r=i;
            }
            while(cnt==n){ //string s is found in the window [j,i]
                if(r-l+1>i-j+1){ // If length of existing answer window is more than the current ans window, update l and r (Better answer)
                    l=j;
                    r=i;
                }
                if(m1[s[j]]&&m2[s[j]]==m1[s[j]]){ //If a character which is in m1 and its count in current window falls below required value, break from loop
                    cnt--;
                }
                m2[s[j]]--; //Remove useless characters in the front of current window if any!
                j++;
                
            }
        }
    }
    if(l==-1 && r==-1)return "-1";
    else return s.substr(l,r-l+1);
}


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        cout<<smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  