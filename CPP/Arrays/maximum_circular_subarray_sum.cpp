/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-04
 * @desc Maximum circular subarray sum 
 */

/**
 * Key Observation : Maximum Sub array Sum may be formed with or without wrap around
 * With Wrap Around : Maximum Sub array Sum = Sum of all elements in array - Minimum Sub array Sum (Can be found by inverting all the elements)
 * Without Wrap Around : Kadane's Algorithm.
 * Note : Edge Case for above approach - If all the elements are negative, return the maximum element of array
*/
#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int n){ //Kadane's Algo
    int max_sum=a[0],curr_sum=a[0];
    for(int i=1;i<n;i++){
        curr_sum=max(curr_sum+a[i],a[i]);
        max_sum=max(curr_sum,max_sum);
    }
    return max_sum;
}
int maxCircularSubarraySum(int a[], int n){
    bool flag=true;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            flag=0;
            break;
        }
    }
    if(flag) return *max_element(a,a+n); //If all the elements are negative, then return maximum element.
    
    int  max_sum=maxSubArraySum(a,n); //Maximum Subarray Sum, without wrap around.
    
    int total=0;
    for(int i=0;i<n;i++)total+=a[i]; //Sum of all elements

    // To find Minimum Sub Array Sum, invert all the elements of array, so that all the negative elements become positive and vice versa.
    //Now find Maximum Sub Array Sum in the inverted array (Will be formed by postive elements which were negative earlier in the original array). Multiplying the res with -1 gives the minimum sub array sum
    for(int i=0;i<n;i++)a[i]*=-1; 
    int min_sum=-1*maxSubArraySum(a,n);
    
    return max(total-min_sum,max_sum);
}

int main()
 {
	int t;
	
	cin>> t;
	
	while (t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    //inserting elements
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	        
	    cout << maxCircularSubarraySum(arr, n) << endl;
	    
	}
	
	return 0;
} 