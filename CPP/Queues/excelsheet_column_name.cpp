/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-07
 * @desc Given a column number, find its corresponding Excel column name.
 */
#include<bits/stdc++.h>
using namespace std;

//Can generate all Column Names upto n ):-
string columnName(int n){
    int i=0;
    string res="",s="abcdefghijklmnopqrstuvwxyz";
    queue<string>q;
    q.push("");
/**
 * Don't write pre or post increments of loop terminating variables with logical operators in between them, 
 * might get short circuited and operation may not be performed.
 * while(res==""||n--) when res=="", n-- is not performed. ):-
*/
    while(res==""||n){ 
        res=q.front()+s[i++];
        i=i%26;
        if(i==0)q.pop();
        q.push(res);
        n--;
    }
    return res;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<columnName(n)<<endl;
    }
    return 0;
}
