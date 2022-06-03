/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-28
 * @desc Find all possible paths that the rat can take to reach from source (0,0) to destination(n-1,n-1) in an nxn matrix. 
 *       The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
 *       Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
 *       Note: In a path, no cell can be visited more than one time.
 */

//Time Complexity - O((n^2)^3), Space Complexity - O(L*X) i.e., Length of path X no.of paths
#include <bits/stdc++.h>
using namespace std;


vector<vector<bool>>visited; //Maintained so that we will not include same cell multiple times in a single path
vector<string>res;

void findRatPaths(vector<vector<int>>& v, int n, int i,int j, string path){
    if(i<0 || j<0 || i>=n|| j>=n ||visited[i][j] ) return ; //Dont't explore any cell which is out of bounds or a cell which has visited==1
    
    else if(i==n-1 && j==n-1 && v[i][j]){ // Destination Reached , check if destination cell is blocked or not and then push the path into res vector
        res.push_back(path);
        return ;
    }
    else{
        if(v[i][j]==1){ //Explore if current cell is unblocked

            visited[i][j]=1; //Mark the cell as visited so that you don't explore this cell again in the children function calls

            findRatPaths(v,n,i-1,j,path+'U'); //Explore the cell which is on top of current cell, and append 'U' to path
            findRatPaths(v,n,i+1,j,path+'D'); //Explore the cell which is down to the current cell, and append 'D' to path
            findRatPaths(v,n,i,j+1,path+'R'); //Explore the cell which is on right of current cell, and append 'R' to path
            findRatPaths(v,n,i,j-1,path+'L'); //Explore the cell which is on left of current cell, and append 'L' to path

            visited[i][j]=0; //While Backtracking, mark visited of current cell as false, because this cell might be inlcuded in other heirarchiel function calls
        }
    }
    
}
vector<string> findPath(vector<vector<int>> &v, int n) {
    res.clear(); //res vector may contain the paths computed in the previous test case
    visited.clear(); 
    for(int i=0;i<n;i++)visited.push_back(vector<bool>(n,false));
    findRatPaths(v,n,0,0,""); //Start exploring from initial position
    sort(res.begin(),res.end());
    return res;
}

/**
 * class Solution{
    public:
    vector<char>move={'U','R','D','L'};
    vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    bool visited[5][5];
    vector<string>paths;
    
    void dfs(vector<vector<int>>&a, int i, int j, string path){
        int m=a.size(),n=a[0].size();
        if(i==m-1 && j==n-1){
            if(a[i][j])paths.push_back(path);
            return;
        }
        if(i<0||j<0||i==m||j==n||visited[i][j]||!a[i][j])return;
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int x=i+dir[k][0],y=j+dir[k][1];
            dfs(a,x,y,path+move[k]);
        }
        visited[i][j]=false;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        paths.clear();
        memset(visited,0,sizeof(visited));
        dfs(m,0,0,"");
        return paths;
    }
};
 */
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  