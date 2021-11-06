/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-06 
 * @desc Given an integer array nums where every element appears three times except for one, which appears exactly once. 
 *       Find the single element and return it.
 */
#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(nlogM), Space Complexity - O(1) 

int singleNumber(vector<int>& nums) {
    int ones=0,twos=0;
    for(auto x:nums){
        ones=(ones^x)&(~(twos)); //If a no. is seen one time, it will be held in ones. 
        twos=(twos^x)&(~(ones)); //If a no. is seen two times, it will be held in twos. (three times==> erased off, ones and twos reset to 0)
    }
    return ones;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        cout << singleNumber(arr)<<endl;
    }
    return 0;
} 