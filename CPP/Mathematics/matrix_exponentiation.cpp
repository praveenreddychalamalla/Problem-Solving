/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-21
 * @desc Matrix Exponentiation
 * 
 * Note : Same concept can be applied to transformations and finding nth fibonacci number.
 * Transformation Example : p1=(x1,y1) - transforming p1 by relation (x+y,2y-x) for 100 times, 
 * is same as A^100 multiplied with matrix P where A= [ 1  1] and P=[x1]
 *                                                    [-1  2]       [y1]
 */

//Time Complexity & Space Complexity - (Multiplication COmplexity) x log n
#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;

struct matrix{
    int mat[2][2];
};

matrix identity(){
    matrix A;
    A.mat[0][0]=1;A.mat[0][1]=0;
    A.mat[1][0]=0;A.mat[1][1]=1;
    return A;
}

matrix multiply(matrix A, matrix B){
    matrix C;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int val=0;
            for(int k=0;k<2;k++) val+=A.mat[i][k]*A.mat[k][j];
            C.mat[i][j]=val;
        }
    }
    return C;
}

//Power of a matrix
matrix power(matrix A, int n){
    if(n==0)return identity();
    matrix X=power(A,n/2);
    if(n%2) return multiply(A,multiply(X,X));
    else return multiply(X,X);
}


int main() {
  matrix A,B;
  A.mat[0][0]=2;A.mat[0][1]=4;
  A.mat[1][0]=1;A.mat[1][1]=1;
  B=power(A,2);
  for(int i=0;i<2;i++){
      for(int j=0;j<2;j++)cout<<B.mat[i][j]<<" ";
      cout<<endl;
  }
  return 0;
}
