/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-23
 * @desc Given an array nums of n integers and a target sum, 
 * return an array of all the unique quadruplets [nums[i], nums[j], nums[k], nums[l]]
 *  such that:
    0 <= i, j, k, l < n
    i, j, k, and l are distinct.
    nums[i] + nums[j] + nums[k] + nums[l] == target
    You may return the answer in any order.
 */

//Time Complexity - O(n^2), Space Complexity - O(n^2)
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& a, int target) {
    int n=a.size();
    unordered_map<int,int>freq;
    for(auto x:a)freq[x]++;
    unordered_map<long long, map<pair<int,int>,int>>m; 
    vector<vector<int>>v;
    map<vector<int>,int>res;
    for(int i=0;i<n;i++){ //Form O(n^2) unique pairs 
        for(int j=i+1;j<n;j++){
            int x=min(a[i],a[j]),y=max(a[i],a[j]);
            long long sum=(long long)a[i]+(long long)a[j];
            m[sum][make_pair(x,y)]=1; 
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x1=a[i],x2=a[j];
            long long x=target-((long long)a[i]+(long long)a[j]);
            if(m.find(x)!=m.end()){
                for(auto e:m[x]){
                    bool flag=true;
                    map<int,int>temp;
                    int x3=e.first.first,x4=e.first.second;
                    temp[x1]++;temp[x2]++;temp[x3]++;temp[x4]++;
                    for(auto e1:temp){ //Check if there are sufficient number of elements to form quadraplet
                        if(e1.second>freq[e1.first]){
                            flag=false;
                        }
                    }
                    if(flag){
                        vector<int>sol={x1,x2,x3,x4};
                        sort(sol.begin(),sol.end());
                        res[sol]=1;
                    }
                }
            }
        }
    }
    for(auto e:res){
        v.push_back(e.first);
    }
    return v;
}
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
        vector<vector<int>> result = fourSum(A, sum);
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