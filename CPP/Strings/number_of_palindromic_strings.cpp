/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-13
 * @desc Given two integers N and K, the task is to find the count of palindromic strings of length lesser than or equal to N, with first K characters of lowercase English language, 
 * such that each character in a string doesn’t appear more than twice. Answer can be very large, so, output answer modulo 109+7
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;

long long int mod=1e9+7;
int nPr(int n,int r){
    long long int res=1,x=n-r;
    while(n>x){
        res=(res*n)%mod;
        n--;
    }
    return res;
}
//In n length string choose first n/2 positions fill them with available k characters i.e.,(k*(k-1)*(k-2)*....(k-n/2) {Remaining n/2 positions gets fixed as it is a palindrome}
int palindromicStrings(int n, int k){
    if(n==1)return k; //Base case - 1 length strings with k characters available 
    if(n%2==0){
        if(n/2<=k)return (nPr(k,n/2)+palindromicStrings(n-1,k))%mod; 
        else return palindromicStrings(n-1,k);
    }
    else{
        if(n/2+1<=k)return (nPr(k,n/2+1)+palindromicStrings(n-1,k))%mod;
        else return palindromicStrings(n-1,k);
    }
}

int main() {
   	
   	int t;
   	cin >> t;
   	while(t--){
   		int n, k;
   		cin >> n >> k;
   		cout << palindromicStrings(n, k) << "\n";
   	}

    return 0;
} 