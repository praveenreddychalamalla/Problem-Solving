/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-24
 * @Given a positive integer N, find the factors of N.
 */

//Time Complexity - O(sqrt(n))
#include<bits/stdc++.h>
using namespace std;

vector<pair<long long int,long long int>> factorize(long long int n){
    vector<pair<long long int,long long int>>v;
    long long int m=sqrt(n);
    for(long long int i=1;i<=m;i++){
        if(n%i==0){
          v.push_back({i,n/i});
        }
    }
    //If n is a perfect square, No.of distinct factors of n = v.size()*2-1
    //If n is not a perfect square, No.of distinct factors of n = v.size()*2
    return v; 
}

int main() {
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        vector<pair<long long int,long long int>>factors=factorize(n);
        for(auto e:factors)cout<<e.first<<" "<<e.second<<endl;
    }
    return 0;
}
