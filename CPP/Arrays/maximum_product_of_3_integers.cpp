/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-06 
 * @desc Maximum Product of 3 integers in an array.
*/
#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n), Space Complexity - O(1)
long long int maxProduct3(int a[],int n){ 
  if(n<=3){
    switch(n){
      case 1 : return a[0]; 
      case 2 : return a[0]*a[1];
      case 3 : return a[0]*a[1]*a[2];
      default : return 0;
    }
  }
  else{
    //Max Product can be product of 3 maximum integers or product of 2 minimum integers and 1 maximum integer(if -ve integers are present)
    long long max_prod,min1=INT_MAX,min2=INT_MAX,max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
    for(int i=0;i<n;i++){
      if(a[i]>max1){
        max3=max2;
        max2=max1;
        max1=a[i];
      }
      else if(a[i]>max2){
        max3=max2;
        max2=a[i];
      }
      else if(a[i]>max3){
        max3=a[i];
      }
      if(a[i]<min1){
        min2=min1;
        min1=a[i];
      }
      else if(a[i]<min2){
        min2=a[i];
      }
    }
    max_prod=max(max1*max2*max3, max1*min1*min2);
    return max_prod;
  }
}
int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<< maxProduct3(a,n);
  }
  return 0;
}
