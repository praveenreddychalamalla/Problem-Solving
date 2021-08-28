/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-27
 * @desc Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x.
 *       Find whether element x is present in the matrix or not.
 */

//Time Complexity - O(n+m), Space Complexity - O(1)
#include<bits/stdc++.h> 
using namespace std;

bool search(vector<vector<int> > a, int m, int n, int x) 
    {
        int  i=0,j=n-1;
        while(i<m &&j>=0){
            if(a[i][j]==x)return true;
            if(a[i][j]<x)i++;
            else j--;
        }
        return false;
    }


int main() { 
	int t;
    cin>>t;
    while(t--){

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        if (search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 

