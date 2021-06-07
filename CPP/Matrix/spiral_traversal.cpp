/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-06 
 * @desc Given a matrix of size r,c . Traverse in Spiral Form
 */
#include <bits/stdc++.h> 
using namespace std; 

//Time Complexity = O(r*c), Space Complexity = O(1).
vector<int> spirallyTraverse(vector<vector<int> >a, int r, int c) 
{
    int top=0,down=r-1,left=0,right=c-1,dir=0;
    vector<int>v;
    while(top<=down && left<=right){
        switch(dir){
            case 0: for(int i=left;i<=right;i++)v.push_back(a[top][i]); //Move left to right when dir=0, in the row pointed by top
                    top++; 
                    break;
            case 1: for(int i=top;i<=down;i++)v.push_back(a[i][right]);//Move top to bottom when dir=1, in the col pointed by right
                    right--;
                    break;
            case 2: for(int i=right;i>=left;i--)v.push_back(a[down][i]); //Move right to left when dir=2, in the  row pointed by down
                    down--;
                    break;
            case 3: for(int i=down;i>=top;i--)v.push_back(a[i][left]); //Move bottom to top when dir=3, in the col pointed by left
                    left++;
                    break;
        }
        dir=(dir+1)%4;
    }
    return v;
}
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }
        vector<int> result = spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
} 