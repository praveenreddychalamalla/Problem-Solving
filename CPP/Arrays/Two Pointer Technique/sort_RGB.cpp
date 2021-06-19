/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-17
 * @desc Sort an array containing characters 'R', 'G', 'B'. Try to accomplish in only one pass of array.
 */
#include<bits/stdc++.h>
using namespace std;

//Time Complexity - O(n), Space Complexity - O(1).
//Note: Counting sort can also be performed within the same time and space bounds as above, but requires 2 passes of array. One for counting and one for updating
void sortRGB(char a[],int n){

  int r=n,b=-1; //Have 2 pointers r-collects r's,  b-collects b's
  int i=0;
  while(i<r){
    if(a[i]=='R'){ //If you hit 'R', let it get collected by r pointer. 
      swap(a[i],a[--r]);//Decrement r and swap the contents pointed by traversal pointer and r.
     // Note: But don't increment the traversal pointer, because we don't know what traversal pointer is pointing to right now, might be an 'R', 'G', 'B'. Hence will be examined and appropriate action is performed in the next iteration
    }
    else if(a[i]=='B'){  //If you hit 'B', let it get collected by b pointer. 
      swap(a[i],a[++b]); //Increment b and swap the contents pointed by traversal pointer and b.
      i++;
    }
    else i++; //Increment if traversal pointer points to 'G'
  }
  return;
  
}
int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sortRGB(a,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;

  }
  return 0;
}
