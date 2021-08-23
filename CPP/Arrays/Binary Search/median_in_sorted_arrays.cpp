/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-23
 * @desc Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.
 */
#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O(log(min(m,n))), Space Complexity - O(1)

double MedianOfArrays(vector<int>& a, vector<int>& b){

    if(a.size()>b.size())return MedianOfArrays(b,a);//Make sure you apply binary search on smaller array

    int m=a.size(),n=b.size();
    if(m==0){
        if(n%2) return b[n/2];
        else return (b[n/2]+b[n/2-1])/2.0;
    }
    int k=(m+n)/2; //Find the split for k the element
    int low=max(0,k-n),high=min(k,m);
    while(low<=high){
        int p1=(low+high)/2;
        int p2=k-p1;
        int l1=p1==0?INT_MIN:a[p1-1];
        int l2=p2==0?INT_MIN:b[p2-1];
        int r1=p1==m?INT_MAX:a[p1];
        int r2=p2==n?INT_MAX:b[p2];
        
        if(l1<=r2 && l2<=r1){ //Desired Partition is found
            if((m+n)%2)return min(r1,r2); //We require k+1 the element (Assuming 1 based positions). Hence pick the min from right side of partitions 
            else return (max(l1,l2)+min(r1,r2))/2.0; //Pick 1 from left and one from right
        }
        else{
            if(l1>r2)high=p1-1;
            else low=p1+1;
        }
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
            cin>>array1[i];
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
            cin>>array2[i];
        cout<<MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}
