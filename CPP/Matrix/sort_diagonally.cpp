/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-07
 * @desc Given a NxM Matrix, sort the Diagonal elements in descending order in the upper triangular matrix, 
 * 		 sort the Diagonal elements in ascending order in the lower triangular matrix,
 * 		 keep the principal diagonal elements in tact.
 * 
 */

// Time Complexity - O((n+m)*log(Max(n,m))), Space Complexity O(max(n,m))
#include <bits/stdc++.h>
using namespace std;

void sortDiagonal(vector<vector<int>>& a, int row, int col,int n,int m, bool flag=false){ //For Each diagonal
    vector<int>v;
    int i=row,j=col,k=0;
    if(!flag){
        while(i<n&& j<m){ //Traverse along the diagonal and push all the elements into vector
            v.push_back(a[i][j]);
            i++;
            j++;
        }
        i=row,j=col;
        sort(v.begin(),v.end(),greater<int>()); //Sort in descending order
        while(i<n && j<m){
            a[i][j]=v[k++];
            i++;
            j++;
        }
    }
    else{
        while(i<n&& j<m){ //Traverse along the diagonal and push all the elements into vector
            v.push_back(a[i][j]);
            i++;
            j++;
        }
        i=row,j=col;
        sort(v.begin(),v.end()); //Sort in descending order
        while(i<n && j<m){
            a[i][j]=v[k++];
            i++;
            j++;
        }
    }
}
    
void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
    vector<int>v;
    int i=0,j=m-1;
    while(j>0){ //Sort each diagonal in Upper Triangular Matrix
        sortDiagonal(matrix,i,j,n,m);
        j--;
    }
    i++; 
    while(i<n){ //Sort each diagonal in Lower Triangular Matrix
        sortDiagonal(matrix,i,j,n,m,true);
        i++;
    }
}

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;

        int inputline2[n*m];
        for (int i = 0; i < n*m; ++i)
            cin>> inputline2[i];
        vector<vector<int> > matrix( n , vector<int> (m, 0));

        for(int i=0; i<n; i++) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = inputline2[i * m + j]; 
            }
        }
        
        diagonalSort(matrix, n, m);

        // print the modified matrix
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) { 
                cout << matrix[i][j] << " "; 
            } 
            cout << endl; 
        }    
    }
    return 0;
}
