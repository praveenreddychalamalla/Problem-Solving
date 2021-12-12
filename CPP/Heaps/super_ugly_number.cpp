/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-07
 * @desc A super ugly number is a positive integer whose prime factors are in the array primes.
 *        Given an integer n and an array of integers primes, return the nth super ugly number.
 */

//Time Complexity - O(n log K) {check once}, Space Complexity - O(k)
#include <bits/stdc++.h>
using namespace std;

class Compare{
    public:
    bool operator()(pair<int,pair<int,int>>& a, pair<int,pair<int,int>> & b){
        return a.first>b.first;
    }
};
int nthSuperUglyNumber(int n, vector<int>& primes) { //Primes is a sorted array of prime numbers
    
    vector<int>ugly(1,1); 
    /** The next ugly numbers have to be generated from the existing ugly numbers,
     *  by multiplying with any of the primes whichever gives the minimum (will be however greater than the largest existing ugly number )*/

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,Compare>pq; //{val,{prime,last index of ugly array used for this prime}}
    for(auto x:primes){
        pq.push({x,{x,0}});
    }
    int cnt=1;
    while(cnt<n){
        int u=pq.top().first;
        ugly.push_back(u);
        while(pq.top().first==u){ //Update index of all the other primes which produces the same ugly number. 
            pair<int,pair<int,int>>temp=pq.top();
            pq.pop();
            temp.second.second++;
            temp.first=((long long)temp.second.first)*ugly[temp.second.second];
            pq.push(temp);
        }
        cnt++;
    }
    return ugly.back();
}

int main()
{
    int n, k;
    int t;
    cin>>t;
    while(t--)
    {
    
    	cin >> n;
        cin>>k;
        vector<int> primes(k);
    	for(int i = 1;i<= k; ++i)
    	{
    		cin >> primes[k];
    	    cout << nthSuperUglyNumber(n,primes)<< endl;
    	}
    }
	return 0;
}  