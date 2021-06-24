/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-24
 * @inorder traversal in Array representation of binary tree. 2*i+1=Left Child,2*i+2=Rightt Child, -1 in array represents NULL.
 */
#include<bits/stdc++.h>
using namespace std;
void inorder(int i,int a[],int n,vector<int>&res){
  if(a[i]!=-1){ //Equivalent to if(root!=NULL)
    if(2*i+1<n) inorder(2*i+1,a,n,res); //Visiting Left Child - visit only if left child is within bounds
    res.push_back(a[i]);
    if(2*i+2<n) inorder(2*i+2,a,n,res); //Visiting Right Child - visit only if Righit child is within bounds
  }
}
vector<int> findInorderTraversal(int a[],int n){
  vector<int>res;
  inorder(0,a,n,res);
  return res;
}
int main() {
  int t;
  cin>>t;
  while (t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i]; 

    vector<int>res=findInorderTraversal(a,n);

    for(auto i:res)cout<<i<<" ";
    cout<<endl;
  }
  
  
  return 0;
}
