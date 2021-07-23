/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-23
 * @desc Extended Eucledian GCD Algorithm.
 * 
 * Solving for ax+by=c. For this to have integer solutions, c must be a multiple of gcd(a,b)
 * Solve ax+by=g where g=gcd(a,b) which ultimately solves ax+by=c.
 * Example : To solve 3x+4y=11, solve 3x+4y=1 which yields the values x=-1, y=1.
 *           Multiply obtained x,y with 11/1 which gives the required values x=-11, y=11.
 */
#include<bits/stdc++.h>
using namespace std;
int extendedEuclidean(int a, int b, int& x, int& y){
    if(b==0){ //if b==0, gcd=a
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=extendedEuclidean(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);  //b*x1+(a-floor(a/b)*b)*y1=g ==> b*(x1-floor(a/b)*y1)+a*y1=g
    return d;
}
int gcd(int a,int b){//Eucledian GCD
    if(b==0)return a;
    else return (b,a%b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,x,y;
        cin>>a>>b>>c;
        int g=(a>b)?gcd(a,b):gcd(b,a);
        int k=c/g;
        extendedEuclidean(a,b,x,y);//Before calling, check if there is a solution for ax+by=c
        cout<<k*x<<" "<<k*y<<endl;
    }
    return 0;
}