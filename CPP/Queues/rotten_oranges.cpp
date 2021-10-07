/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-23
 * @desc Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
         0 : Empty cell
         1 : Cells have fresh oranges
         2 : Cells have rotten oranges
     what is the minimum time required to rot all oranges.
     A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1]  in unit time. 
 */

//Time Complexity - O(mxn), Space Complexity - O(mxn)
#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& a) {
    int m=a.size(),n=a[0].size();
    queue<pair<int,int>>q1,q2;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==2)q1.push({i,j}); //Push all rotten oranges into a queue
        }
    }
    int cnt=0;
    while(!q1.empty()){
        bool flag=false;
        while(!q1.empty()){
            int i=q1.front().first,j=q1.front().second; //Push the newly rotten oranges into other queue
            q1.pop();
            if(i-1>=0 && a[i-1][j]==1){
                q2.push({i-1,j});
                a[i-1][j]=2;
                flag=true;
            }
            if(i+1<m && a[i+1][j]==1){
                q2.push({i+1,j});
                a[i+1][j]=2;
                flag=true;
            }
            if(j-1>=0 && a[i][j-1]==1){
                q2.push({i,j-1});
                a[i][j-1]=2;
                flag=true;
            }
            if(j+1<n && a[i][j+1]==1){
                q2.push({i,j+1});
                a[i][j+1]=2;
                flag=true;
            }
        }
        if(flag)cnt++;
        swap(q1,q2); //interchange q1 with q2
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1)return -1; //Check if there is any fresh orange still
        }
    }
    return cnt;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		int ans = orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}