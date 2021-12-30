/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-29
 * @desc Job Sequencing with deadlines
 */

//Time Complexity - O(n * log n), Space Complexity - O(max_deadline) 

#include<bits/stdc++.h>
using namespace std; 

struct Job { 
    int id;	 
    int dead; 
    int profit; 
}; 


class Solution {
    public:
    static bool comp(Job &a, Job &b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp); //sort the jobs in decreasing order of their profits
        set<int>s;
        for(int i=0;i<=100;i++)s.insert(i); //Given 1<=deadlines<=100
        int profit=0,cnt=0;
        for(int i=0;i<n;i++){
           auto it=s.lower_bound(arr[i].dead); //For every job try to find the available slot . Largest element smaller than x(deadline)
           if(it==s.begin())continue; //No slot is avaliable, ignore the job
           else{
               it--; //Decrementing the iterator fetches the the required slot
               s.erase(it);
               cnt++;
               profit+=arr[i].profit;
           }
        }
        return vector<int>({cnt,profit});
    } 
};