/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-13
 * @desc Given an infix expression in the form of string str. Convert this infix expression to postfix expression.
 */
#include<bits/stdc++.h>
using namespace std;

string infixToPostfix(string s){
    map<char,int>m;
    m['+']=1;m['-']=1;m['*']=2;m['/']=2;m['^']=3; //Precedence
    stack<char>st;
    string res="";
    for(auto c:s){
        if(c>='a'&&c<='z')res+=c; // If character is operand, append it to result
        else if(c=='(')st.push('(');// If character is '(', push it onto the stack
        else{
            if(c==')'){ 
                while(!st.empty() && st.top()!='('){ //Pop the stack until '(' is seen at top of stack.
                    res+=st.top();
                    st.pop();
                }
                st.pop(); //Remove '('
            }
            else{
                while(!st.empty() && m[c]<=m[st.top()]){ //Pop the stack until the precendence of operator on top of the stack is less than current operator
                    res+=st.top();
                    st.pop();
                }
                st.push(c); //push the operator onto to the stack
            }
        }
    }
    while(!st.empty()){ //append all the operators if any present in the stack to result
        res+=st.top();
        st.pop();
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        cout<<infixToPostfix(exp)<<endl;
    }
    return 0;
}