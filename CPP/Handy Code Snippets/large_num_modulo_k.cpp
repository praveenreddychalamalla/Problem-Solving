#include<bits/stdc++.h>
using namespace std;
long long int mod=10000000+7;
long long int base;
long long int exp;
long long int power(long long int i){
    if(i==0)return 1;
    long long int temp=power(i/2);
    if(i)return (base*temp*temp)%mod; //If base is large enough : (((base*temp)%mod)*temp)%mod;
    else return (temp*temp)%mod;
}
int main(){
    cin>>base>>exp;
    cout<<power(exp);

}