/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-09
 * @desc Given an array of integers -10^6<=a[i]<=10^6, find the smallest missing positive number.
 */

//Time Complexity - O(n), Space Complexiy - O(1)
#include<bits/stdc++.h>
using namespace std;

int separate(int a[],int n){ //Separates aray into non +Ve integers(Left side) and positive integers(Right side) in O(n) Time
    int i=-1; //i - Collection Pointer. Collect all non +Ve integers 
    for(int j=0;j<n;j++){
        if(a[j]<=0){ // If you hit any non +Ve integer, increment collection pointer and swap with traversal pointer.
            swap(a[++i],a[j]);
            a[i]=1; //We have nothing to do with zeroes and -ve numbers later, hence erase them and assign some positive value
        }
    }
    return i+1; //Return the starting index of +Ve integers
}  
int missingNumber(int a[], int n) 
{   
    int k=separate(a,n); //Separate all +Ve integers and non +Ve integers (-Ve integers and zero). K= starting index of +Ve integers
    
/**
 * Note: Given n integers, then smallest missing postive number <=n+1. In worst case your array might have [1,n]
 * Start iterating from the index of first +ve integer. For every integer z from here on, if z<=n, indicate it's presence by making the element at location z negative 
 * 
*/
    for(int i=k;i<n;i++){ 

        int z=abs(a[i]); //must use abs value, as the elements are not sorted, the element at a[i] might have converted to -ve, if integer i+1 is seen earlier in array
        if(z<=n && a[z-1]>0) a[z-1]*=-1;
    }
    int ele=n+1;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            ele=i+1;
            break;
        }
    }
    return ele;
    
} 

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0; 
} 