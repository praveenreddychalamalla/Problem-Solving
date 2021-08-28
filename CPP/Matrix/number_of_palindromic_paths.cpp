/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-18
 * 
 * @desc Given a matrix containing lower alphabetical characters only of size n*m. 
 * We need to count the number of palindromic paths in the given matrix.
 * A path is defined as a sequence of cells starting from top-left cell and ending at bottom-right cell. 
 * We are allowed to move to right and down only from current cell.
 */

//Time Complexity - O(n^2 * m^2), Space Complexity - O(n^2 * m^2)
#include<bits/stdc++.h>
using namespace std;

int mod =1e9+7;
//i & j points to front of path, x & y points to end of path.
int computePaths(vector<vector<char>>& a, int i,int j, int x, int y,vector<vector<vector<vector<int>>>>&dp){
    if(i>x||j>y||a[i][j]!=a[x][y])return 0; // Check upto halfway
    if(abs(i-x)+abs(j-y)<=1)return 1; // [i,j] and [x,y] points to same character in the path or adjacent characters in the path which implies palindrome is found
    if(dp[i][j][x][y]!=-1)return dp[i][j][x][y]; //If same sub problem is computed earlier, use the computed result.
/**
 * Having matched the characters a[i][j] and a[x][y], We can explore in 4 different paths i.e, 
 * move front position to right or down (a[i][j+1],a[i+1][j]) and move end position to left or up (a[x][y-1],a[x-1][y]).
 * Hence Check paths from resulted 4 positions recursively at every instance if characters are matched.
*/
    else return dp[i][j][x][y]=((computePaths(a,i,j+1,x-1,y,dp)+
                                computePaths(a,i,j+1,x,y-1,dp))%mod+
                                (computePaths(a,i+1,j,x-1,y,dp)+
                                computePaths(a,i+1,j,x,y-1,dp))%mod)%mod; 
}
int countPalindromicPaths(vector<vector<char>>matrix){
    int m=matrix.size(),n=matrix[0].size();
    //similar to a[m][n][m][n] 4D vector, Used for memoization. Only Half of it is going to be used.
    vector<vector<vector<vector<int>>>>dp(m,vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(n,-1)))); 
    return computePaths(matrix,0,0,m-1,n-1,dp);
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		int ans =countPalindromicPaths(matrix);
		cout << ans <<"\n";
	}
	return 0;
} 