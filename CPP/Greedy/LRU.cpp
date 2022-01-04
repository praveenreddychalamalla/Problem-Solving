/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-01-01
 * @desc LRU Page Replacement Policy
 */

//Time Complexity - O(n*c), Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        int cnt=0;
        unordered_map<int,int>m;
        for(int i=0;i<N;i++){
            if(m.size()<C){
                if(m.find(pages[i])==m.end())cnt++;
                m[pages[i]]=i;
            }
            else{
                if(m.find(pages[i])!=m.end())m[pages[i]]=i;
                else{
                    cnt++;
                    int key,val=INT_MAX;
                    for(auto e:m){
                        if(e.second<val){
                            key=e.first;
                            val=e.second;
                        }
                    }
                    m.erase(key);
                    m[pages[i]]=i;
                }
            }
        }
        return cnt;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
} 