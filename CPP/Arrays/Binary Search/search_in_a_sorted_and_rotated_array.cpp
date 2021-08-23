/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-23
 * @desc Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K.
 *       The task is to find the index of the given element K in the array A.
 */

//Time Complexity - O(log n), Space Complexity - O(1)
#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> a, int x) {
    int n=a.size();
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;

        if(a[m]==x)return m;

        if(a[m]<=a[r]){
            if(a[m]<=x && x<=a[r])l=m+1;
            else r=m-1;
        }
        else{  
            if(a[l]<=x && x<=a[m])r=m-1;
            else l=m+1;;
        }
    }
    return -1;
}
int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
