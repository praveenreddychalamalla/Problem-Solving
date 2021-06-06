/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-06 
 * @desc Given a Non -ve integer as String, Remove K digits from the number so that the new number is the smallest possible
 */
#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n), Space Complexity - O(n)
string removeKDigits(string s, int k) {
    int n=s.size();
    if(k==0)return s;
    if(k>=n)return "0"; //We can remove all digits
    stack<char>st;

    for(char c: s){ //Process every character of the string
        // Push curr element into stack only when top of stack is less than or equal to curr element. 
        // If curr element < top of stack, it is a dip. Hence, check if we can remove it. If k>0 remove the dip. (Pop)

        while(!st.empty()&&c<st.top() && k>0){ // Pop until curr_element<top of stack and k>0 and stack is not empty. Removing dips formed
            st.pop();
            k--;
        }
        if(c!='0' || !st.empty() )st.push(c); // If Stack is empty and the character is '0' We need not push it into stack. No value for zeroes at the beginning of a number. 
    }

    while(k-- && !st.empty()) st.pop(); //If k is still positive, then remove the largest k digits

    string res="";
    while(!st.empty()){
        res+=st.top(); //Don't perform res=st.top()+res; It turns out to be O(n^2) operation.
        st.pop();
    }
    reverse(res.begin(),res.end()); //When popped all the digits from stack and appended to "", You get the required reversed number
    
    return (res==""?"0":res); //If stack is empty and res=="" , return "0" not "".
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int k;
        string s;
        cin>>s>>k;
        cout<< removeKDigits(s,k);
    }
    return 0;
}
