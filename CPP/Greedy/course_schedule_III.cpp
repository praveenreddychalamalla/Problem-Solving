/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-23
 * @desc Leetcode : 630. Course Schedule III
 */

#include<bits/stdc++.h>
using namespace std;

class Solution { //Time Complexity - O(n log n), Space Complexity - O(n) 
public: 
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](vector<int>a, vector<int>b){return a[1]<b[1];}); //sort the courses by their end times
        priority_queue<int,vector<int>>pq;
        int day=0;
        for(auto course:courses){
            int duration=course[0],lastDay=course[1];
            day+=duration;//Schedule the current course
            pq.push(duration);
            if(day>lastDay){ //If the current day exceeds the deadline, erase the course with longer duration
                day-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};

class Solution1 { //Time Complexity - O(2^n), Space Complexity - (n) . Memoization ==> TC - O(n*M), space - O(n*M).  Space can be reduced to O(M) as well. (M= max end time of course)
public:
    int solve(vector<vector<int>>& courses, int day, int i){
        if(i==courses.size())return 0;
        int duration=courses[i][0],lastDay=courses[i][1];
        if(day+duration<=lastDay){ //You can choose to schedule or not schedule the current course.
            return max(1+solve(courses,day+duration,i+1),solve(courses,day,i+1));
        }
        else return solve(courses,day,i+1); //Cannot schedule the current course. Ignore
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](vector<int>a, vector<int>b){return a[1]<b[1];});
        return solve(courses,0,0);
    }
};