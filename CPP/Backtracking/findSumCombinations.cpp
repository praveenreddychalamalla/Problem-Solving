/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-22
 * @desc Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B.
 * The same number may be chosen from the array any number of times to make B.
 * Note:
 *       1. All numbers will be positive integers.
 *       2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *       3. The combinations themselves must be sorted in ascending order.
 */
#include <bits/stdc++.h>
using namespace std;
/**
 * If sum == 0, add current vector to res.
 * If sum becomes negative, ignore the subproblem from there, without exploring further and backtrack.
 * else add current index element into vector and call the function again with sum=sum-a[i], remove the element after returning
 * 
*/
void findSumCombinations(vector<int>&a,int sum, vector<vector<int>>& res, vector<int>& v,int i,int n){
    if(sum==0){ //Combination found
        res.push_back(v);
        return ;
    }
    while(i<n && sum-a[i]>=0){
        v.push_back(a[i]); //Add current index element into vector 
        findSumCombinations(a,sum-a[i],res,v,i,n); //Call function with sum-a[i];
        v.pop_back();//Remove the current index element after returning
        i++; //Explore the combinations other elements
    }
}
vector<vector<int> > combinationSum(vector<int> &a, int s) {
    map<int,int>m;
    for(auto x:a)m[x]=1;
    a.clear();
    for(auto e:m)a.push_back(e.first); //Remove duplicates and sort the vector. As map is ordered, sorted sequence goes into vector.
    vector<vector<int>>res;
    vector<int>v;
    int n=a.size();
    findSumCombinations(a,s,res,v,0,n);
    return res;
}
/**
 * 
 * class Solution {
  public:
    set<vector<int>>res;
    void solve(vector<int>&a, int i, int s, vector<int>& list){
        if(s==0){
            res.insert(list);
            return;
        }
        if(i==a.size()) return;
        if(a[i]<=s){
            list.push_back(a[i]);
            solve(a,i,s-a[i],list);
            list.pop_back();
        }
        solve(a,i+1,s,list);
    }
    void removeDuplicatesAndSort(vector<int>&a){
        set<int>s;
        for(auto e:a)s.insert(e);
        a.clear();
        for(auto e:s)a.push_back(e);
        return;
    }
    vector<vector<int> > combinationSum(vector<int> &a, int s) {
        res.clear();
        vector<int>list;
        removeDuplicatesAndSort(a);
        solve(a,0,s,list);
        vector<vector<int>>ans;
        for(auto e:res)ans.push_back(e);
        return ans;
    }
};
 */
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        vector<vector<int>> result = combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}