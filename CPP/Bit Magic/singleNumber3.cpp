/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-06
 * @desc Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
 *       Find the two elements that appear only once. You can return the answer in any order.
 */
#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(nlogM), Space Complexity - O(1) 

 vector<int> singleNumber(vector<int>& nums) {
        long long xy=0;
        vector<int>res(2,0);
        for(auto n:nums)xy^=n; //xy will hold the xor of required two elements. Remaining gets cancelled off with each other
        xy&=-xy; //Obtain the left most set bit(Least significant set bit). This operation is equivalent to x &(~x+1)
        //Required no.s differ at this bit
        for(auto n:nums){
            if((xy&n)==0) res[0]^=n; //x,y falls into different groups
            else res[1]^=n;
        }
        return res;
    }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<int>res=singleNumber(arr);
        cout << res[0]<<" "<<res[1]<<endl;
    }
    return 0;
} 