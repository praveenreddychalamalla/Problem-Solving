/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-29
 * @desc Fractional Knapsack
 */

//Time Complexity - O(n * log n), Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;


struct Item{
    int value;
    int weight;
};


class Solution{
    public:
   
    static bool comp(pair<double,Item>&a, pair<double, Item>&b){
        return a.first>=b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n) {
        vector<pair<double,Item>>v;
        for(int i=0;i<n;i++){
            double ratio=arr[i].value/(1.0*(arr[i].weight));
            v.push_back({ratio,arr[i]});
        }
        double profit=0;
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<n;i++){
            if(W>=v[i].second.weight){
                profit+=v[i].second.value;
                W-=v[i].second.weight;
            }
            else{
                profit+=W*v[i].first;
                break;
            }
            
        }
        return profit;
    }
        
};

