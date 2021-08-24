/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-15
 * @desc Given an array A[] of N positive integers. Find the maximum of j - i subjected to the constraint of A[i] <= A[j].
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;

/**
 * Optimal way for every element you have to pick the first index from the end where 
 * the value of element is greater than or equal to current element. Similarly if you traverse from right look for first index from start.
 * 
 * For an element a[i], you don't have to consider a[i] for left index if there is an element smaller than a[i] on left side of it. 
 * Similarly, if there is a greater element on right side of it, You don't have to consider this j for right index. 
 * Pre compute the things.
 * */

int maxIndexDiff(int a[], int n){ 
    int left[n],right[n];
    left[0]=a[0];
    right[n-1]=a[n-1];
    for(int i=1;i<n;i++)left[i]=min(left[i-1],a[i]);
    for(int i=n-2;i>=0;i--)right[i]=max(right[i+1],a[i]);
/**
 *As right[] array is a monotonically non Increasing sequence, for any element in a[] as we need an element just greater than or equal to it from this right[] array,
 * perform binary search and get the index - But this approach goes to O(nlogn)
 */ 
    int res=0,i=0,j=0;
    while(j<n && i<n){
        if(left[i]<=right[j]){
            res=max(res,j-i);
            j++;
        }
        else i++;
    }
    return res;
    
}

int main() 
{
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int arr[num];

        for (int i = 0; i<num; i++)
            cin>>arr[i];
        
        cout<<maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends