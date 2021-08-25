/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-24
 * @desc Given two strings, one is a text string, txt and other is a pattern string, pat. 
 * The task is to print the indexes of all the occurences of pattern string in the text string. 
 * For printing, Starting Index of a string should be taken as 1.
 */

//Time Complexity - O(m+n), Space Complexity - O(m). n=|text|, m=|pattern|
#include<bits/stdc++.h>
using namespace std;

vector<int> computeLPSArray(string s, int n){
    vector<int>lps(n,0); //Longest Prefix (Proper Prefix) which is also a Suffix. If s="a",LPS[0]=0 , "a" is a prefix which is also suffix but not proper prefix
    int len=0,i=1; //lps[0]=0, hence start from 1.
    while(i<n){
        if(s[len]==s[i]){ //If characters are matched, increment both len and i. len points to ending of longest prefix which is also suffix for string ending at i
            lps[i]=len+1;
            len++;
            i++;
        }
        else{
            if(len!=0){ //If characters pointed by len and i don't match, rollback len to the index where it matches part of substring from pattern (Longest Prefix Suffix)  
                len=lps[len-1]; //Main Idea of KMP
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
vector <int> search(string pat, string txt){
    int n=txt.length(),m=pat.length();
    vector<int>lps=computeLPSArray(pat,m),res;
    int i=0,j=0;
    while(i<n){ //This is almost similar to LPS computation
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else i++;
        }
        if(j==m){ //Don't reset j to 0. There may be overlap from the current substring which forms one more match when further indices are considered
            res.push_back(i-m+1);
            j=lps[j-1]; //Set j to lps of its previous index
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        vector <int> res = search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
