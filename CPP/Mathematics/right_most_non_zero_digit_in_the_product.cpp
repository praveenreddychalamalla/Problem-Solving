/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-21
 * @desc You will be given an array A of N non-negative integers. 
 * Find the rightmost non-zero digit in the product of array elements. 1<=n<=10^5, 0 ≤ A[i] ≤ 10^5
 */

/*Extract 5's and 2's from every number to pair up for 10 all the numbers*/

#include<bits/stdc++.h> 
using namespace std; 

int rightmostNonZeroDigit(int n, int a[]){
    long long prod;
    int cnt=0;
    for(int i=0;i<n;i++)if(a[i]==0)return -1;
    for(int i=0;i<n;i++){
        if(a[i]==0)return -1;
        while(a[i]%5==0){ //Count no.of 5's you can get from every number
            a[i]/=5;
            cnt++;
        }
    }
    for(int i=0;i<n;i++){
        while(a[i]%2==0 && cnt){ //For every 2 if there is a 5, remove, they contribute 0 to prod
            a[i]/=2;
            cnt--;
        }
    }
    prod=cnt>0?5:1; //Any no.of 5's if left extra, intialize prod to 5.
    for(int i=0;i<n;i++){
        prod=(prod*a[i])%10; //As no two numbers in the array can produce 10, focus only on last digit in the product
    }
    return prod;
}
int main() { 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        cout <<rightmostNonZeroDigit(n, A) << endl;
    }
    return 0; 
}  