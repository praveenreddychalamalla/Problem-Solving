/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-02
 * @desc Given an array arr[] of N elements.
 *       Find the number of non-empty subsets whose product of elements is less than or equal to a given integer K.
 */

//Time Complexity O(n* 2^(n/2)), Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

/**
 * Meet in the middle approach - Divide the array into two halves, compute all possible subset products of both halves.
 * Iterate through subset products and compute the no.of valid subsets
 */

void computeProducts(vector<long long>&a,int i, int n,long long prod, int k,vector<long long>&products){ //O(2^n)
    if(i>=n){
        if(prod<=k)products.push_back(prod);
        return ;
    }
    computeProducts(a,i+1,n,prod*a[i],k,products);
    computeProducts(a,i+1,n,prod,k,products);
    
}

int numOfSubsets(int a[], int n, int k) {
    
    vector<long long>v1,v2,p1,p2;
    for(int i=0;i<n;i++){
        if(a[i]>k)continue;
        if(i<=n/2)v1.push_back(a[i]);
        else v2.push_back(a[i]);
    }

    computeProducts(v1,0,v1.size(),1,k,p1); //v1.size()<=n/2 ==> O(2^(n/2)
    computeProducts(v2,0,v2.size(),1,k,p2); //v2.size()<=n/2 ==> O(2^(n/2)
    
    sort(p1.begin(),p1.end()); // O(2^(n/2) * log (2^(n/2))) ==> O(n * 2^(n/2))
    sort(p2.begin(),p2.end());  // O(2^(n/2) * log (2^(n/2))) ==> O(n * 2^(n/2))
    
    int cnt=0;
    
    int m=p1.size();
 /** If x is an element in p1 which is a possible subset product,
  * any number which is less than k/x from p2  will form product less than k, look for such no.of instances in p2.
  */
    for(int i=0;i<m;i++){
        cnt += upper_bound(p2.begin(),p2.end(),k/p1[i])-p2.begin();
    }
    
    return cnt-1; //Remove empty subset product
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;


        cout << numOfSubsets(arr,N,K) << endl;
    }
    return 0;
} 