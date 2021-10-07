/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-23
 * @desc Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, 
 * each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 */

//Time Complexity - O(n), Space Complexity - O(1)
#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string s){
    string res;
    vector<int>m(26,0);
    queue<char>q; //At max 26 characters might be pushed into queue 
    for(auto c:s){
        m[c-'a']+=1;
        if(m[c-'a']==1)q.push(c); //Push character only if it is seen for the first time
        while(!q.empty() && m[q.front()-'a']!=1)q.pop(); //Pop the the front of queue unless a character with count == 1 is encountered
        if(q.empty())res+='#';
        else res+=q.front();
    }
    return res;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		string ans =FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}