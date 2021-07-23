/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-21
 * @desc Nth Fibonacci Number - Application of binary exponentiation
 * 
 * Nth Fibonacci Number : A^n when multiplied with B where A=[1 1] B=[1] gives [ Fn+1 ]
 *                                                           [1 0]   [1]       [  Fn  ]
 */

//Time Complexity - O(log n), Space Complexity - O(log n)
#include<bits/stdc++.h>
using namespace std;

struct matrix{
    long long int mat[2][2];
};

matrix identity(){ //Returns Identity matrix
    matrix I;
    I.mat[0][0]=1,I.mat[0][1]=0;
    I.mat[1][0]=0,I.mat[1][1]=1;
    return I;
}

matrix multiply(matrix A, matrix B){ //2X2 Matrix Multiplication
    matrix C;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            long long int val=0;
            for(int k=0;k<2;k++){
                val+=A.mat[i][k]*B.mat[k][j];
            }
            C.mat[i][j]=val;
        }
    }
    return C;
}

matrix power(matrix A, int n){ //Power of a Matrix
    if(n==0)return identity();
    matrix X=power(A,n/2);
    if(n%2) return multiply(A,multiply(X,X));
    else return multiply(X,X);
}

long long int getNthFibonacciNumber(int n){ //Returns Fn
    if(n<=1)return 1;
    matrix fib;
    fib.mat[0][0]=1;fib.mat[0][1]=1;
    fib.mat[1][0]=1;fib.mat[1][1]=0;
    
    return power(fib,n).mat[0][0];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<getNthFibonacciNumber(n-1)<<endl;
    }
}
