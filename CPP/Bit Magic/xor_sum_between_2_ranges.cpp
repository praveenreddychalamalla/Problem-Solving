/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-12
 * Given 2 ranges [a-b], [c-d] find the sum of xor of every element in the range [a-b] with every other element in the range [c-d]
 */
#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
vector<int>countSetBitsForEachBitPosition(int n)
{
    int cnt=0,a=0,b=0;
    vector<int>set_bits(32,0);
    if(n==0)return set_bits;
    int x=(int)(log2(n)); 
    while(n){
        a=(1<<x-1);  
        b=n-(1<<x)+1;
        for(int i=0;i<x;i++)set_bits[i]+=a;
        set_bits[x]+=b;

        cnt+=a+b+1;  
        n&=~(1<<x);   
        while(n && x>0){
            if(n&1<<x)break; 
            x--;
        }
    }
    return set_bits;
    
}
void solve(){
    int a,b,c,d,k=(int)mod;
    long long int sum=0;
    cin>>a>>b>>c>>d;
    vector<int>x(32,0),y(32,0),v1,v2;
	  vector<long long int>res(32,0);

    v1=countSetBitsForEachBitPosition(b);
    v2=countSetBitsForEachBitPosition(a-1);
 
    for(int i=0;i<32;i++)x[i]=v1[i]-v2[i];

    v1=countSetBitsForEachBitPosition(d);
    v2=countSetBitsForEachBitPosition(c-1);
    for(int i=0;i<32;i++)y[i]=v1[i]-v2[i];

    for(int i=0;i<32;i++){
      res[i]=((y[i]*(b-a+1-x[i]))%k+(x[i]*(d-c+1-y[i]))%k)%k;
    }
    for(int i=0;i<32;i++){
      sum=(sum%k+((res[i]%k)*(((long long int)(1))<<i)%k)%k)%k;
    }
    cout<<sum<<endl;
}
int main() {
  int t;
  cin>>t;
  while(t--)
	  solve();
  return 0;
}
