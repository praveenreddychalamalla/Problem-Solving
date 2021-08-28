/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-27
 * @desc Given a boolean 2D array of n x m dimensions where each row is sorted.
 *       Find the 0-based index of the first row that has the maximum number of 1's.
 */

//Time Complexity - O(m+n), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > a, int m, int n) {
    int i=0,j=n-1,res=-1;
    while(i<m && j>=0){
        if(a[i][j]==1){ //Remain in the same row, move left
            j--;
            res=i;
        }
        else i++; // Move to next row, if you hit a zero
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        auto ans =rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
