/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-03 
 * @desc Generate Parentheses
 */

#include <bits/stdc++.h>
using namespace std;
//Time Complexity - O(2^n *n ), Space Complexity O(2*n*x) {x= # valid parenthesis}
class Solution{
    public:
    vector<string>res;
    void generateParenthesis(int open,int close,string s){
        if(open==0 && close==0){
            res.push_back(s);
            return;
        }
        //String copy into s at every instance is O(n) time (:-
        if(open) generateParenthesis(open-1,close,s+"("); //You can open a "(" at any instance
        if(close>open)generateParenthesis(open,close-1,s+")"); //You can only put ")" if there are any open parenethesis( "("). Leads you to generate only valid parentheis
    }
    vector<string> AllParenthesis(int n) {
        res.clear();
        generateParenthesis(n,n,"");
        return res;
    }
};

/**
 *  Generate all possible parenthesis(valid and invalid) and verify their validity. Time and space complexity remain same.
 *  class Solution{
        public:
        vector<string>res;

        void generateParenthesis(int open,int close,string s){
            if(open==0 && close==0){
                if(isValidParenthesis(s))res.push_back(s);
                return;
            }
            if(open) generateParenthesis(open-1,close,s+"(");
            if(close)generateParenthesis(open,close-1,s+")");
        }

        bool isValidParenthesis(string s){
            stack<char>st;
            for(auto e:s){
                if(e=='(')st.push('(');
                else{
                    if(st.empty()) return false;
                    else st.pop();
                }
            }
            return st.empty();
        }
        
        vector<string> AllParenthesis(int n) {
            res.clear();
            generateParenthesis(n,n,"");
            return res;
        }
    };
 */