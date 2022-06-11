/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-11
 * @desc Kth smallest element in an array
 */
#include <bits/stdc++.h>
using namespace std;

class Solution1{ //Time Complexity - O(n), Space Complexity - O(log n)
    public:
    int getMedian(int a[], int n){
        sort(a,a+n);
        return a[n/2];
    }
    int findGoodPivot(int a[], int l, int r){ //Returns the good pivot element
        int n=r-l+1;
        int median[(n+4)/5],i;
        for(i=0;i<n/5;i++){ //Divide into groups of 5
            int j=5*i+l; 
            median[i]=getMedian(a+j,5);
        }
        if(i*5<n)median[i]=getMedian(a+5*i+l,n%5),i++; //Last group
        return (i==1)?median[0]:median[findRank(median,0,i-1,i/2+1)];
    }
    int partition(int a[], int l, int r, int pivot){//Partition the array w.r.t pivot and place pivot in its correct position and return the index.
        for(int i=l;i<=r;i++){
            if(a[i]==pivot){
                swap(a[i],a[r]);
                break;
            }
        }
        int i=l,j=r;
        while(i<j){
            if(a[i]>a[r])swap(a[i],a[--j]);
            else i++;
        }
        swap(a[i],a[r]);
        return i;
    }
     int findRank(int a[],int l, int r, int rank){ //Returns the index of the element, whose Rank = rank(passed to function)
        if(l>r) return -1;
        int n=r-l+1;
        int pivot=findGoodPivot(a,l,r); //Median of Medians. If you partition w.r.t good pivot (n/4<= x <=3n/4) you will eliminate n/4 numbers in every stage
        int k=partition(a,l,r,pivot);
        if(r-k+1==rank)return k; //Rank of element in the current parition
        else if(rank<r-k+1) return findRank(a,k+1,r,rank);
        else return findRank(a,l,k-1,rank-(r-k+1));
    }
    int kthSmallest(int a[], int l, int r, int k) {
        int n=r-l+1;
        int x=findRank(a,l,r,n-k+1);
        return a[x];
    }
};

class Solution2{  //Time Complexity - O(n), Space Complexity - O(1). Worst Case TC - O(n^2)
    public:

    int findRank(int a[],int l, int r, int rank){
        if(l>r) return -1;
        int n=r-l+1;
        int p=l+rand()%n; //choose random element as pivot
        int k=partition(a,l,r,p); //Partition the array w.r.t a[p]
        if(r-k+1==rank)return k; 
        else if(rank<r-k+1) return findRank(a,k+1,r,rank);
        else return findRank(a,l,k-1,rank-(r-k+1));
    }

    int partition(int a[], int l, int r, int p){
        swap(a[r],a[p]);//Place the pivot at the end of segment and apply standard partition algorithm
        int i=l,j=r;
        while(i<j){
            if(a[i]>a[r])swap(a[i],a[--j]);
            else i++;
        }
        swap(a[i],a[r]);
        return i;
    }

    int kthSmallest(int a[], int l, int r, int k) {
        int n=r-l+1;
        int x=findRank(a,l,r,n-k+1);
        return a[x];
    }
};

class Solution3{  //Time Complexity - O(n log k), Space Complexity - O(log k)
    public:
    int kthSmallest(int a[], int l, int r, int k) {
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<k;i++)pq.push(a[i]);
        for(int i=k;i<=r;i++){
            if(a[i]<pq.top()){
                pq.pop();
                pq.push(a[i]);
            }
        }
        return pq.top();
    }
};