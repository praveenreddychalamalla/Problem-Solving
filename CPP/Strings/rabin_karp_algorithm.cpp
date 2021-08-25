/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-25
 * @desc Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences of pattern string in the text string. 
 *       For printing, Starting Index of a string should be taken as 1.
 * Note: Text and pattern contains smaller case alphabets
 */

/**
 * Time Complexity - |S|*|pat|. Space Complexity - O(1).
 * But Average Time Complexity is (|S|+|pat|) which is linear. 
 * */
#include<bits/stdc++.h>
using namespace std;

 vector <int> search(string pat, string txt){
    int n=txt.length(),m=pat.length();
    vector<int>res;
    if(n<m){
        res.push_back(-1);
        return res;
    }

    long long p=1e9+7,win_hash=0,pat_hash=0,q=1; //q stores 26^m, p is a large prime number
    int i=0;
    for(;i<m;i++){ //Compute the hashes for pattern and window of length m (substring of text) from text 
        win_hash=(win_hash*26+txt[i]-'a')%p;
        pat_hash=(pat_hash*26+pat[i]-'a')%p;
        q=(q*26)%p;
    }
    while(i<n){
        if(win_hash==pat_hash && txt.substr(i-m,m)==pat)res.push_back(i-m+1); //If hash values of current window and hash values of patter are equal, check whether string in current window ==pattern
        win_hash=(win_hash*26+(txt[i]-'a')-(txt[i-m]-'a')*q)%p; //For base 10 : 12345 - Number, 3 length window=123 ==> 123*10+4-1^(1000)=234 , window shifted
        if(win_hash<0)win_hash+=p; //If win_hash<0 indicates overflow, hence add p
        i++;
    }
    if(win_hash==pat_hash && txt.substr(i-m,m)==pat)res.push_back(i-m+1);
    
    if(res.size()==0)res.push_back(-1);
    return res;  
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        vector <int> res = search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
