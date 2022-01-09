/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-09
 * @desc Robot bounded in circle 
 *       On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions.
 *       "G": go straight 1 unit; "L": turn 90 degrees to the left;"R": turn 90 degrees to the right.
 *       The robot performs the instructions given in order, and repeats them forever.
 *       Return true if and only if there exists a circle in the plane such that the robot never leaves the circle
 */

//Time Complexity - O(n), Space Complexity - O(1) 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string s) {
        int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}}; //N,W,S,E
        int x=0,y=0;
        int n=s.length(),j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='G'){
                x+=dir[j][0];
                y+=dir[j][1];
            }
            else if(s[i]=='L') j=(j+1)%4;
            else j=(j+3)%4;
        }
        // If robot reaches to it's initial position, then obviously it is in a circle. 
        //If robot finally faces north, then it will keep on extending. It will not be bounded by any circle. If robot faces any other direction 
        // it will reach to it's initial position in 1 or 2 or 3 trips (:-
        if(x==0 && y==0)return true;
        if(j==0)return false;
        else return true;
        
    }
};