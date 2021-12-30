/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-29
 * @desc You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character.
 *       Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.
 */

//Time Complexity - O(|s|), Space Complexity - O(1) {O(26) worstcase}
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string chooseandswap(string a){
       set<char>s;
       char c1='0',c2='0';
       int n=a.length();
       for(int i=0;i<n;i++)s.insert(a[i]);
       for(int i=0;i<n;i++){ 
           s.erase(a[i]); //Erase the current character from the set
           if(s.empty())break;
           char c=*s.begin(); //Obtain the smallest available character from set and check if it is smaller than the current character 
           if(c<a[i]){
               c1=a[i];
               c2=c;
               break;
           }
       }
       if(c1=='0')return a;
       for(int i=0;i<n;i++){
           if(a[i]==c1)a[i]=c2;
           else if(a[i]==c2)a[i]=c1;
       }
       return a;
    }
    
};

int main(){
    Solution obj;
	int t;
	cin >> t;
	while(t--){	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}