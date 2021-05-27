#include <bits/stdc++.h>
using namespace std;
//O(nlogk)
vector<int> kthLargest(int k, int a[], int n) {
    priority_queue<int,vector<int>,greater<int>>pq; //MIN_HEAP
    vector<int>v;
    int i=0;
    //Bulid a min heap which holds k largest elements
    while(pq.size()!=k){   // kth largest element is always maintained at root(Smallest among k elements is same as kth largest element )
        pq.push(a[i]);
        if(pq.size()==k)v.push_back(pq.top());
        else v.push_back(-1);
        i++;
    }
    for(;i<n;i++){
        if(pq.top()<=a[i]){  //If incoming element< root element , it cannot be among in k largest elements of heap, hence ignore
            pq.push(a[i]);  //If incoming element>= root, push ele into heap and pop one element, so that again kth largest comes to top
            pq.pop();
        }
        v.push_back(pq.top());
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        vector<int> v = kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  