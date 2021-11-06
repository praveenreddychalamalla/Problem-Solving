/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-03
 * @desc Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), 
 *       the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.
 */

//Time Complexity - O(9*n*n) {9 possibilities for every position on board}, Space Complexity - O(n*n)

#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<char>>&a , int x, int y, char c){
    for(int i=0;i<9;i++)if(a[x][i]==c)return false;
    for(int i=0;i<9;i++)if(a[i][y]==c)return false;
    x=3*(x/3);
    y=3*(y/3);
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++)
            if(a[i][j]==c)return false;
    }
    return true;
}
bool sudokuSolver(vector<vector<char>>&a, int i, int j){
    if(i==9)return true; //Board filled
    if(j==9)return sudokuSolver(a,i+1,0); //start filling next row
    if(a[i][j]!='.') return sudokuSolver(a,i,j+1); //skip the current cell
    
    for(char c='1';c<='9';c++){ //Explore all 9 possibilities
        if(isValid(a,i,j,c)){
            a[i][j]=c; //If valid, assign 
            if(sudokuSolver(a,i,j+1))return true; //Fill next positions
            a[i][j]='.'; //Remove the placed character and backtrack
        }
    }
    return false;
    
}
void solveSudoku(vector<vector<char>>& board) {
    sudokuSolver(board,0,0);
}
void printGrid(vector<vector<char>>& a){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		vector<vector<char>> grid(9,vector<char>(9,'.'));
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		solveSudoku(grid); 
        printGrid(grid);  
	}
	
	return 0;
} 