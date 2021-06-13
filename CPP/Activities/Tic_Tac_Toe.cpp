/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-13
 * @desc 2 Player Tic Tac Toe game on 3X3 Board
 */
#include<iostream>
using namespace std;
struct status{ //Winner can be checked in O(1) time
    int row[3]={0,0,0};
    int col[3]={0,0,0};
    int principal_diag=0;
    int counter_diag=0;
};
int placeMove(char board[][3],char c,int i,int j,status& player,int n){
    board[i][j]=c;
    player.row[i]+=1;
    player.col[j]+=1;
    if(i==j) player.principal_diag+=1; // For any position on principle diagonal, i==j.
    if(i+j==n-1) player.counter_diag+=1; // For any position on counterdiagonal, i+j=n-1 on nxn board.
    
    if(player.row[i]==n || player.col[j]==n || player.principal_diag==n || player.counter_diag==n)return 1;
    return 0;
}
void showBoard(char board[][3],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void startTicTacToe(){
    int won=0,count=0,chance=0,i,j,n=3;
    string player_won="";
    status X,O;
    char board[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    while(!won && count<=9){
        showBoard(board,3);
        if(chance==0){
            cout<<"X turn"<<endl ;
            cout<<"Enter the position to place X: ";
            cin>>i>>j;
            while(!(i>=0 && i<n && j>=0 && j<n)){
                cout<<"Enter a Valid Position: ";
                cin>>i>>j;
            }
            won=placeMove(board,'X',i,j,X,n); //Places Move and checks if there is winner in O(1) time ):-
             if(won==1){
                player_won='X';
            }
        }
        else{
            cout<<"O turn"<<endl;
            cout<<"Enter the position to place O: ";
            cin>>i>>j;
             while(!(i>=0 && i<n && j>=0 && j<n)){
                cout<<"Enter a Valid Position";
                cin>>i>>j;
            }
            won=placeMove(board,'O',i,j,O,n);
            if(won==1){
                player_won='O';
            }
        }
        chance=(chance+1)%2;
        count++;
    }
    if(won==1){
        showBoard(board,3);
        cout<<player_won+" has won the game!"<<endl;;
    }
    else cout<<"Game is Draw!!"<<endl;
}
int main(){
    int play=1;
    cout<<"Welcome to 2 Player Tic Tac Toe game on 3X3 Board"<<endl;
    while(play){
        startTicTacToe();
        cout<<"Enter 1 to play again, 0 to exit"<<endl;
        cout<<"Choice: ";
        cin>>play;
    }
    return 0;
}