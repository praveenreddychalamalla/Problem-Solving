/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-06 
 * @desc Permute the characters of s so that they match the order that order was sorted. 
 *      More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
 */
#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(nlogn).
class Solution {
    public:
        static bool comp(char& c1,char& c2){ //Can access only static members
            return temp[c1-'a']<temp[c2-'a'];
        }
        string customSortString(string order, string s) {
            temp.resize(26,INT_MAX);
            int n=order.size();
            for(int i=0;i<n;i++)temp[order[i]-'a']=i;
            sort(s.begin(),s.end(),comp);
            return s;
        }
    private:
        static vector<int>temp; 

};
vector<int> Solution::temp; //static members must be declared outside the class
int main() {
  
  int t;
  cin>>t;
  while(t--){
    string s,order;
    cin>>order>>s;
    Solution ob= Solution();
    cout<<ob.customSortString(order,s)<<endl;
  }
  return 0;
}