/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-24
 * @desc Leetcode : 780. Reaching Points .
 * Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point (sx, sy) to the point (tx, ty) through some operations, or false otherwise.
 * The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).
 */
#include <bits/stdc++.h>
using namespace std;

class Solution { // Time Complexity - O(log(min(tx,ty))), Space Complexity - o(1)
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        /** As (sx,sy)-->(tx,ty) is a strictly increasing operation, there is only one path.
         *  It's ambigous if start from (sx,sy) and convert it to (tx,ty). 
         *  If we start from (tx,ty), the path is staright forward. If tx>ty the previous point is (tx-ty,ty) else (tx,ty-tx)
         */
        while(tx>sx && ty>sy){
            if(tx>=ty)tx%=ty; //Instead of subtracting ty multiple times from tx. similar to gcd. [97,3]-->[94,3]--->[1,3]
            else ty%=tx;
        }
        
        if(tx==sx && ty>=sy && (ty-sy)%tx==0)return true;
        else if(ty==sy && tx>=sx && (tx-sx)%ty==0)return true;
        else return false;
    }
};