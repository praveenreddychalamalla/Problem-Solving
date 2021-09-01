/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-01
 * @desc Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.
 */

//Time Complexity - O(n), Space Complexity - O(n)

#include<bits/stdc++.h>
using namespace std;

/**Transform the 0s in array to -1s, Now find the Largest subsarray with sum=0.*/

int maxLen(int a[], int n){
    for(int i=0;i<n;i++)if(a[i]==0)a[i]=-1;
    unordered_map<int,vector<int>>m;
    m[0].push_back(-1);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        m[sum].push_back(i);
    }
    int res=0;
    for(auto e:m){
        res=max(res,e.second.back()-e.second.front());
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}  