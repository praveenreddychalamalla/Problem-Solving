/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-08
 * @desc Find nth catalan number (n<=19). catalan(n)=(2nCn)/(n+1)
 */
//Time Complexity - O(n^2), space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int catalanNumber(int n) {
    if(n<=0)return 1;
    vector<int>catalan(n+1,0);  //Cn= (k=0 to n-1) ∑Ck Cn−1−k, n≥2. i.e, Cn=C0Cn-1 * C1Cn-2 * C2Cn-3 *....CiCn-i-1....*Cn-1C0
    catalan[0]=1;
    catalan[1]=1;
    for(int i=2;i<=n;i++){
        int res=0;
        for(int j=0;j<i;j++){
            res+=catalan[j]*catalan[i-j-1];
        }
        catalan[i]=res;
    }
    return catalan[n];
}
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<catalanNumber(n);
    };
	return 0;
}
