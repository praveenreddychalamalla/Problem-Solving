/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-01 19:47:53
 * @desc N Queens - Backtracking
 */
#include <bits/stdc++.h>
using namespace std;
int board[15]={0};
vector<vector<int>>v;

bool isSafe(int k, int col){
   //Check all the rows from [1,k) if any queen is placed in the same column 'col' or if the position (k,col) is under attack
    for(int i=1;i<k;i++){ 
        if(board[i]==col||abs(i-k)==abs(col-board[i])) return false; //(x1,y1) (x2,y2) lies on the same diagonal iff abs(x1-x2)==abs(y1-y2)
    }
    return true;
}
//From the perspective of board, queen 'k' is the row k . We keep proceeding by placing queen 'k' in the valid column
void nQueens(int k, int n){ 
    for(int i=1;i<=n;i++){ 
        if(isSafe(k,i)){ //Check if queen k can be placed in column 'i'. 
          board[k]=i; //Placing a queen 'k' in column 'i' is same as placing a queen at [k,i] in square board.
            if(k==n){
                vector<int>temp;
                for(int j=1;j<=n;j++)temp.push_back(board[j]);
                v.push_back(temp);
            }
            else nQueens(k+1,n);
        }
        //If (k,i) is not safe, backtrack
    }
}
vector<vector<int>> solveNQueen(int n){
    if(n==1){
        vector<int>temp={1};
        v.push_back(temp);
        return v;
    }
    else if(n>3)
        nQueens(1,n);
    return v;
}
/**
 * public:
    vector<vector<int>>res;
    void solve(int n,vector<int>rows){
        if(n==0){
            for(int i=0;i<rows.size();i++)rows[i]++; //columns are mentioned as 0 indexed. 
            res.push_back(rows);
            return;
        }
        for(int i=0;i<rows.size();i++){
            if(isSafe(rows,n-1,i)){ //Check if a queen can be placed in row n-1 and col i
                rows[n-1]=i;
                solve(n-1,rows);
                rows[n-1]=-1;
            }
        }
    }
    bool isSafe(vector<int>rows, int r, int c){
        for(int i=r+1;i<rows.size();i++){
            if((rows[i]==c)|| (abs(rows[i]-c)==abs(r-i)))return false;
        }
        return true;
    }
    vector<vector<int>> nQueen(int n){
        res.clear();
        vector<int>rows(n,-1);
        solve(n,rows);
        sort(res.begin(),res.end());
        return res;
    }
};
 * 
 */
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> ans = solveNQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
} 