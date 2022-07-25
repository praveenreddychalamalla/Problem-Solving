/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-07-24
 * @desc Given an empty set of intervals, implement a data structure that can:
 *       Add an interval to the set of intervals.
 *       Count the number of integers that are present in at least one interval.
 */

//Time Complexity - O(nlogn), Space Complexity - O(n)
#include <bits/stdc++.h>
using namespace std;

class CountIntervals {
public:
    int cnt=0;
    map<int,int>m;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {

        auto it=m.upper_bound(left);

        if(it!=m.begin() && left-1<=prev(it)->second) it--; //Interval - [4,6]. If compared as left<=prev(it)->second, [2,3],[7,8] ==> [2,3] will remain same 

        while(it!=m.end() && it->first<=right+1){ //Interval - [4,6]. If compared as it->first<=right+1, [2,3],[7,8] ==> [7,8] will remain same 
            cnt-=(it->second)-(it->first)+1;
            left=min(left,it->first);
            right=max(right,it->second);
            m.erase(it++);
        }
        m[left]=right; //[2,8]
        cnt+=right-left+1;
    }
    
    int count() {
        return cnt;
    }
};
