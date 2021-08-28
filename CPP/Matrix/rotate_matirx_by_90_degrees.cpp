
/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-27
 * @desc Given a square matrix[][] of size N x N. 
 *      The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.
 */

//Time Complexity - O(n*n), Space Complexity - O(1)
#include<bits/stdc++.h>
using namespace std;

/**
 * Starting with j=i+1, in transpose function will ensure that you iterate only upper triangular matrix 
 * and swap the entries with corresponding ones in lower triangular matrix
*/
void transpose(vector<vector<int>>& a,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){ 
            swap(a[i][j],a[j][i]); 
        }
    }
}
void rotate(vector<vector<int> >& a){
    int n=a.size();
    void(transpose(a,n));
    for(int j=0;j<n;j++){ //Reverese the elements in every column . If the rotation is 90 degree clock wise, reverse the elements in every row
        int l=0,r=n-1;
        while(l<r){
            swap(a[l][j],a[r][j]);
            l++;r--;
        }
    }
}


int main(){
    int t;
    cin>>t; 
    while(t--){
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
