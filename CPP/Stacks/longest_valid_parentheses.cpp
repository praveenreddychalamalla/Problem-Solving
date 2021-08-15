/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-11
 * @Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.
 */

//Time Complexity - O(|s|), Space Complexity - O(|s|)
#include <bits/stdc++.h>
using namespace std;


int maxLength(string s){
    stack<int>st;
    st.push(-1);
    int res=0;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='(')st.push(i);
        else{
            st.pop(); //Match up the closing bracket with opening bracket. 
            if(!st.empty()) //If stack is not empty. The substring from the index i (i=top of stack) to current index is a valid parentheses.
                res=max(i-st.top(),res); //Update if better answer is found
            else st.push(i); //If stack is empty and ')' is the current character, spoils the parenthesis. Hence push the current index into stack so that better answer can be found if any exist 
            
        }
        
    } 
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        cout<<maxLength(S)<<"\n";
    }
    return 0;
}  