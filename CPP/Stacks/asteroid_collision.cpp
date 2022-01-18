/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-18
 * @desc We are given an array asteroids of integers representing asteroids in a row.
 *       For each asteroid, the absolute value represents its size, and the sign represents its direction (+ve = right, -ve =left). 
 *       Each asteroid moves at the same speed. Find out the state of the asteroids after all collisions.
 *       If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        int n=a.size();
        vector<int>res,temp;
        for(int i=0;i<n;i++){
            if(a[i]>0)st.push(a[i]);
            else{
                int x=abs(a[i]);
                while(!st.empty()&& x>st.top())st.pop(); //Current asteroid will burst all the smaller asteroids moving right
                if(st.empty())res.push_back(a[i]); //No asteroid is left, hence current keeps on moving left. Add it to result
                else if(st.top()==x)st.pop(); //If current asteroid moving left hits an asteroid moving right with same size, both disappear
            }
        }
        while(!st.empty())temp.push_back(st.top()),st.pop(); //All the left over asteroids keeps on moving to right. (change the order)
        reverse(temp.begin(),temp.end());
        res.insert(res.end(),temp.begin(),temp.end());
        return res;
    }
};