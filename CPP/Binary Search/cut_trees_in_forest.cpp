/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-23
 * @desc There are n trees in a forest. The heights of the trees is stored in array tree[],
 *       where tree[i] denotes the height of the ith tree in the forest. 
 *       If the ith tree is cut at a height H, then the wood collected is tree[i] - H, provided tree[i] > H. 
 *       If the total woods that needs to be collected is exactly equal to k, find the height H at which every tree should be cut 
 *       (all trees have to be cut at the same height). If it is not possible then return -1 else return H.
 */

//Time Complexity - O(n log h), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;

int find_height(int a[], int n, int k){
    int l=0,r=*max_element(a,a+n); //Height at which the trees should be cut must lie between 0 and largest height
    while(l<=r){
        int m=(l+r)/2,wood=0; 
        for(int i=0;i<n;i++){
            if(a[i]>m)wood+=a[i]-m;
        }
        if(wood==k)return m; //Answer found
        if(wood>k)l=m+1; //If each tree is cut at a height m, wood obtained is more than required, cutting above m might fetch required wood exactly
        else r=m-1;
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        cout<< find_height(tree,n,k) << endl;
    }
    return 1;
}  