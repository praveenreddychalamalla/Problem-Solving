
/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-09
 * @desc Given an array of size n,  find all elements that appear more than ⌊ n/3 ⌋ times.
 */

//Time Complexity - O(n), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;
/**
 * Similar to finding majority element with Moore's Voting Algo, but here potential candidates could be two.
 * Maximum no.of elements that could appear for more than ⌊ n/3 ⌋ are 2.
*/
 vector<int> majorityElement(int a[],int n) {
    int k=n/3;
    vector<int>v;
    int x=a[0],cnt1=1; //Assign the 1st element to be one of the potential candidate and keep track of its count
    int y=a[0],cnt2=0; 
    for(int i=1;i<n;i++){
/**
 * If current element is among the potential candidates, increment its count appropriately 
 * else try to cancel it with both the current potential candidates (Decrement their counts by 1).
 * Before decrementing the counts of potential candidates, check if any of the counts is zero.
 * If so assign the current element to potential candidate and reset the count.  
*/
        if(a[i]==x)cnt1++; 
        else if(a[i]==y)cnt2++;
        else{
            if(cnt1==0){
                x=a[i];
                cnt1=1;
            }
            else if(cnt2==0){
                y=a[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
    }
    //Check if potential candidates are appearing more than ⌊ n/3 ⌋ times.
    int k1=0,k2=0;
    for(int i=0;i<n;i++){
        if(a[i]==x)k1++;
        else if(a[i]==y)k2++;
    }
    if(k1>k)v.push_back(x);
    if(k2>k)v.push_back(y);
    return v;
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
	    vector <int> res = majorityElement(arr,n);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  