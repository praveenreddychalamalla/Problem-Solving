/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-03
 * @desc Find(x) should return the representative element of disjoint set. Union(x,y) should make the parent of y becomes parent of x
 */

//Time Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;

int find(int a[],int X){
       if(a[X]==X)return X;
       else return find(a,a[X]);
      
}
void unionSet(int A[],int X,int Z){
    int x=find(A,X); //find the representative element of the set to which X belongs to
    int y=find(A,Z);  //find the representative element of the set to which Z belongs to
    A[x]=A[y]; //Modify the representative element
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}
