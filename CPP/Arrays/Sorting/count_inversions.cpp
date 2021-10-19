#include <bits/stdc++.h>
using namespace std;
//Time complexity - O(nlogn)
typedef long long ll;
ll cnt;
void merge(ll a[],ll l,ll m,ll r){
    ll temp[r-l+1];
    ll i=l,j=m+1,k=0;
    while(i<=m && j<=r){
        if(a[i]>a[j]){ //Inversion : i<j and a[i]>a[j]
            temp[k++]=a[j++];
            cnt+=m-i+1; //As left half is sorted, all elements after a[i] will be greater than a[j]
            //Thus all the elements between a[i] and a[m] will also be inversions with a[j].
        }
        else temp[k++]=a[i++];
    }
    while(i<=m) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];
    k=0;
    for(int i=l;i<=r;i++)a[i]=temp[k++];
}
void mergeSort(ll a[],ll l,ll r){
    if(l<r){
        ll m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
ll inversionCount(ll arr[], ll N)
{
    cnt=0;
    mergeSort(arr,0,N-1);
    return cnt;
}

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}