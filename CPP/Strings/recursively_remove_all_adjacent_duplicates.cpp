/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-30
 * @desc Given a string s, remove all its adjacent duplicate characters recursively. 
 */

//Time Complexity - O(n^2), Space Complexity - O(n). Worst case input = Even length palindromic string
#include <bits/stdc++.h>
using namespace std;
string remove(string s){
    int n=s.length();
    if(n<=1)return s;
    string res="";
    int i=0;
    while(s[i]){
        if(s[i]!=s[i+1])res+=s[i++];
        if(s[i+1]&& s[i]==s[i+1]){
            while(s[i+1] && s[i]==s[i+1])i++;
            i++;
        }
    }
    if(res==s)return res; //No adjacent duplicates are present.Hence return
    else return remove(res); //Remove the newly formed adjacent duplicates
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        cout << remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends