/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-01
 * @desc Given an array of integers and a number k, 
 * check if given array can be divided into pairs such that sum of every pair is divisible by k.
 */

#include <bits/stdc++.h>
using namespace std;
bool canPair(vector<int> a, int k) {
    int n=a.size();
    if(n%2)return false;
    
    unordered_map<int,int>m;
    
    for(auto x:a)m[x%k]++;
    if(m[0]%2)return false; //Have to pair these elements within themselves
    int i=1,j=k-1; //Try to Pair the elements with their complement ones.
    while(i<j){
        if(m[i]!=m[j])return false;
        i++;j--;
    }
    if(i==j)if(m[i]%2)return false;//Have to pair these elements within themselves
    return true;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];

        bool ans = canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  