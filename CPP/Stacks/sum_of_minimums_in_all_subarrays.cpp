/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-25
 * @desc Given an integer array. The task is to find the sum of minimums from all subarrays. Since the answer may be large, return the answer modulo 109 + 7.
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include <bits/stdc++.h>
using namespace std;

int sumOfMin(int a[], int n){
	
	stack<int>st;
	vector<int>left(n),right(n); //For every element find its previous smaller element and next smaller element.
	for(int i=0;i<n;i++){
		while(!st.empty()&& a[i]<=a[st.top()]) st.pop(); //Maintaing non decreasing stack 
		left[i]=st.empty()?-1:st.top();
		st.push(i);
	}
	while(!st.empty())st.pop();
	for(int i=n-1;i>=0;i--){
		while(!st.empty()&& a[i]<a[st.top()]) st.pop(); //Maintain strictly increasing stack for PSE / NSE
		right[i]=st.empty()?n:st.top();
		st.push(i);
	}
	long long sum=0,r=1e9+7;
	for(int i=0;i<n;i++){
		long long d1=i-left[i],d2=right[i]-i; //d1 indicates the length of subarray from a[i] to its left in which a[i] can be minimum, similary d2 to it's right side
		//a[i] can be minimum in d1*d2 sub arrays.  Eg : [2, 9, 7, 8, 3, 4, 6, 1] . For ele 3, d1=3, d2=2. 3 can be minimum in 6 sub arrays (Combination of left and right sub arrays)
		sum=(sum+(a[i]*(d1*d2))%r)%r;
	}
	return int(sum);
}
    
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
		cout<<sumOfMin(a,n);
        cout << endl;
    }
    return 0;
}