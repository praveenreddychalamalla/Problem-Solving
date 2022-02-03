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

//Time Complexity - O(n^3), Space Complexity - O(n) (Worst case sums range -[4,4*n])
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    unordered_map<string,vector<int>>res; //set also can be used
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int l=j+1,r=n-1;
            while(l<r){
                long long x=((long long)nums[i]+nums[j])+((long long)nums[l]+nums[r]);
                if(x==target){
                    vector<int>v{nums[i],nums[j],nums[l],nums[r]};
                    sort(v.begin(),v.end());
                    string s=to_string(v[0])+to_string(v[1])+to_string(v[2])+to_string(v[3]);
                    if(res.find(s)==res.end())res[s]=v;
                    l++;
                }
                else if(x<target)l++;
                else r--;
            }
        }
    }
    vector<vector<int>>a;
    for(auto e:res)a.push_back(e.second);
    return a;
}
//Below approach seems to be O(n^2), but in worst case the key may contain O(n^2) indices. Turns out to be O(n^4) - TLE
/*vector<vector<int>> fourSum(vector<int>& nums, int target) {
    unordered_map<string,vector<int>>res;
    unordered_map<int,vector<pair<int,int>>>m;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            m[nums[i]+nums[j]].push_back({i,j});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long x=(long long)target-(nums[i]+nums[j]);
            for(auto e:m[x]){
                int k=e.first,l=e.second;
                if(j<k){
                    vector<int>v{nums[i],nums[j],nums[k],nums[l]};
                    sort(v.begin(),v.end());
                    string s=to_string(v[0])+to_string(v[1])+to_string(v[2])+to_string(v[3]);
                    if(res.find(s)==res.end())res[s]=v;
                }
            }
        }
    }
    vector<vector<int>>a;
    for(auto e:res)a.push_back(e.second);
    return a;
    
}*/

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