#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string>postfix(string s){
        vector<string>res;
        stack<char>st;
        unordered_map<char, int>m;
        m['+']=0;m['-']=0;m['*']=1;m['/']=1;
        string operand="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
                if(operand!="")res.push_back(operand);
                operand="";
                while(!st.empty() && m[st.top()]>=m[s[i]]){
                    string s="";
                    s+=st.top();
                    res.push_back(s);
                    st.pop();
                }
                st.push(s[i]);
            }
            else{
                if(s[i]==' '){
                    if(operand!="")res.push_back(operand);
                    operand="";
                }
                else operand+=s[i];
            }
        }
        if(operand!="")res.push_back(operand);
        while(!st.empty()){
            string s="";
            s+=st.top();
            res.push_back(s);
            st.pop();
        }
        return res;
    }
    int evaluate(vector<string> s){
        stack<string>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=="*"||s[i]=="/"||s[i]=="-"||s[i]=="+"){
                int a=stoi(st.top());
                st.pop();
                int b=stoi(st.top());
                st.pop();
                int val=0;
                if(s[i]=="*")val=a*b;
                else if(s[i]=="/")val=b/a;
                else if(s[i]=="-")val=b-a;
                else val=a+b;
                st.push(to_string(val));
            }
            else{
                st.push(s[i]);
            }
        }
        return stoi(st.top());
    }
    int calculate(string s) {
        vector<string>exp=postfix(s);
        int x=evaluate(exp);
        return x;
    }
};