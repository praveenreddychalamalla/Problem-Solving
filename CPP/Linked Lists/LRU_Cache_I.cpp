/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-08
 * @desc LRU Cache implementation using STL
 */
#include <bits/stdc++.h>
using namespace std;


class LRUCache{
    public:

    unordered_map<int,list<pair<int,int>>::iterator>um;
    list<pair<int,int>>dq;
    int capacity;
    LRUCache(int cap){
        capacity=cap;
    }
    
    int get(int key){   
        if(um.find(key)==um.end())return -1;
        int x=um[key]->second;
        set(key,x); //Order the nodes in the DLL
        return x;
       
    }
    
    void set(int key, int value){   
        if(um.find(key)!=um.end()){
            auto it=um[key];
            dq.erase(it);
        }
        dq.push_front({key,value});
        um[key]=dq.begin();
        if(dq.size()>capacity){
            um.erase(dq.back().first);
            dq.pop_back();
        }
    }
};