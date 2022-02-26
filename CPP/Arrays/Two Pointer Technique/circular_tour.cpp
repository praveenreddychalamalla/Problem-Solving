/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-22
 * @desc Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
 */
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int i=0,j=0,fuel=0;//start from station 0 and empty tank. j=start station, i=curr station
        while(j<n){
            fuel+=gas[i]-cost[i]; //If fuel<0, you cannot reach next station
			
			 /*If fuel is not sufficient to reach next station, You cannot start from any index between start station(j) and current station (i) i.e., [j+1,i]
			  *Because, again you will end up failing to cross the current station. Hence start from station next to the current station i.e, i+1.
			  */
            if(fuel<0){ // You cannot start from [j+1.....i]
                if(i<j)break; //i+1 <= j. You cannot start from any index before j, you already bypassed all those. You cannot even choose any index from [j+1...n-1,0...i] hence not possible to complete tour
                fuel=0;
                j=i+1;
                i=(i+1)%n;  
            }
            else{
                i=(i+1)%n;
                if(i==j)return j;
            }
        }
        return -1;
    }
};
