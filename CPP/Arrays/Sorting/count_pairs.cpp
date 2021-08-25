/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-24
 * @desc Given two arrays X and Y of positive integers, 
 * find the number of pairs such that x^y > y^x (raised to power of) where x is an element from X and y is an element from Y.
 */

//Time Complexity - O((n+m)logn), Space Complexity - O(1).

#include<bits/stdc++.h>
using namespace std;

/**
 * x < y ==> x^y > y^x for all x,y under few exceptions.
 * 
 * Exceptions: 
 * If x < y then x^y > y^x might fail when x=0,1,2,3.
 * If x=0, there will be no y satisfying x^y > y^x (0<1)
 * If x=1, then, only possible y  satisfying x^y > y^x  is 0 
 * If x=2, then, x^y > y^x  fails for y=3,4
 * If x=3, then, y=2 satisfies x^y > y^x though x>y. Special case
 * 
 * If x is other than 0 and 1, then y's less than x satisfying the eqution will be y=0,1
*/

long long getPairs(int x, int b[],int n,long long y[]){
    if(x==0)return 0;
    if(x==1)return y[0];
    long long pairs=(b+n)-upper_bound(b,b+n,x); //No.of elements greater than x in second array
    
    pairs+=(y[0]+y[1]); //If x is positive then y=0,1 satisfies the equation
    if(x==2)pairs-=(y[3]+y[4]);
    if(x==3)pairs+=y[2];
    return pairs;
}

long long countPairs(int a[], int b[], int m, int n){
    sort(a,a+m);
    sort(b,b+n);
    long long y[5]={0}; //Count no.of 0's, 1's, 2's, 3's,and 4's in array Y
    for(int i=0;i<n;i++){
        if(b[i]<=4)y[b[i]]++;
        else break;
    }
    long long cnt=0;
    for(int i=0;i<m;i++){
        cnt+=getPairs(a[i],b,n,y);
    }
    return cnt;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, M, N)<<endl;
	}
}  