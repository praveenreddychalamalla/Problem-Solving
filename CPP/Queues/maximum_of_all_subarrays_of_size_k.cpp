
/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-09
 * @desc Given an array of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.
 */

//Sliding window + Dequeue Approach : Time Complexity - O(n), Space Complexity - O(k)  (Usage of height balanced BST takes, Time Complexity = O(n * log K))
#include <bits/stdc++.h>
using namespace std;


vector <int> max_of_subarrays(int a[], int n, int k){
    vector<int>res;
    deque<int>dq; // Front of dq always contain the maximum element in the current window. Rear of dq always contains the minimum element in current window
    //Use dq to store the indices instead of elements directly. It would be easy to pulse out, if the element in front of deque goes out of current window
    int i=0;
    /**Process all the k elements initially. Insert the current element into dq, only if it is smaller than element at rear end of deque, 
    * else pop the elements from rear end of deque, until deque is empty or you obtain an element which is greater than current element, 
    * so that all the elements left in the deque are greater than current element 
    */
    while(i<k){ 
        while(!dq.empty() && a[*dq.rbegin()]<a[i]) dq.pop_back();
        dq.push_back(i); //Insert the current element into deque from rear end
        i++;
    }
    res.push_back(a[*dq.begin()]);//Push the maximum element in current window
    while(i<n){
        while(!dq.empty() && a[*dq.rbegin()]<a[i]) dq.pop_back();
        dq.push_back(i);
        if(i-*dq.begin()+1>k)dq.pop_front(); //Check if the element at front of deque is out of the current window (Difference between indices)
        res.push_back(a[*dq.begin()]); //Push the maximum element in current window
        i++;
    }
    
    return res;
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  