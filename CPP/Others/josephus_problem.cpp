/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-09
 * @desc Josephus Problem - Game of death in a circle
 */

/**
 * f(n)=1 if n is a power of 2. 
 * f(n) resets to 1 for every power of 2 and keeps incrementing by 2 for every step until next power of 2 is hit
*/
#include<bits/stdc++.h>
using namespace std;

int power(int a, int n){
    if(n==0)return 1;
    int x=power(a,n/2);
    if(n%2)return x*x*a;
    else return x*x;
}
int getSafePosition(int n){
    int x=power(2,floor(log2(n)));
    return 1+2*(n-x);
}

int main() { 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        cout << getSafePosition(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends