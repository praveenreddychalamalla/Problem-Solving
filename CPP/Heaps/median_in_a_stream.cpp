/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-10-23
 * @desc Given an input stream of N integers. The task is to insert these numbers into a new stream and 
 *       find the median of the stream formed by each insertion of X to the new stream.
 */

//Time Complexity - O(nlogn), Space Complexity - O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    priority_queue<int>pq1; //Max Heap
    priority_queue<int,vector<int>,greater<int>>pq2; //Min Heap
    void insertHeap(int &x)
    {
        if(pq1.empty() || x<=pq1.top())pq1.push(x);
        else pq2.push(x);
        if(abs(pq1.size()-pq2.size())>1)balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {   if(pq1.size()>pq2.size()){
            int x=pq1.top();
            pq1.pop();
            pq2.push(x);
            
        }
        else{
            int x=pq2.top();
            pq2.pop();
            pq1.push(x);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(pq1.size()-pq2.size()==1)return pq1.top();
        else{
            double res=(pq1.top()+pq2.top())/2.0;
            return res;
        }
    }
};

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  