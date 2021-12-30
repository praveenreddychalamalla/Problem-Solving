/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-16
 * @desc Kth Smallest Number in Multiplication Table (mxn) - 1 indexed
 */

//Time Complexity - O(mlog(mxn)), Space Complexity - O(1)
#include<bits/stdc++.h>
using namespace std;
int countSmallerThanX(int m, int n, int x){
        int c=0;
        for(int i=1;i<=m;i++){  //Iterate through every row and count no.of elements <= x
            c+=min(n,x/i); // i*n<=x ==> 	n=x/i;  for eg : 2,4,6,8,10 corresponds to  row 2 in mx5 , elements<=9 ==> 9/2=4; ):-
        }
        return c;
    }
    int findKthNumber(int m, int n, int k) {
        int l=1,r=n*m,res=-1;
        while(l<r){
            int mid=(l+r)/2;
            int c=countSmallerThanX(m,n,mid);
            if(c<k){ //Answer lies right half space
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
	
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n,k;
        cin>>m>>n>>k;
        cout<< findKthNumber(m,n,k) << endl;
    }
    return 1;
}  