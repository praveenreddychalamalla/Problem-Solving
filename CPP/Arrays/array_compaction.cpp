/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-06 
 * @desc Compaction Problem in OS. Move all the non zero elements of an array to front retaining their relative positions, leaving zeroes at the end.
*/

#include <bits/stdc++.h>
using namespace std;

//Space Complexity - O(1), Time Complexity - O(n)
void compactArray(int a[],int n){
  int i=-1,j; //i - Collection Pointer (Collects Non Zero elements), j- Traversal Pointer.
  for(j=0;j<n;j++){
    if(a[j]!=0){ //If you hit any non zero element, increment collection pointer and swap the elements pointed by collection pointer and traversal pointer
      swap(a[++i],a[j]);
    }
  }
  return ;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        compactArray(a,n);
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
