#include<bits/stdc++.h>
using namespace std;
//O(nlogM)
int checkBit(int x,int *a,int n){
        int cnt=0;
        for(int i=0;i<n;i++){
            if((x&a[i])==x)cnt++;
        }
        return cnt;
    }
    int maxAND (int a[], int n){
        int res=0,cnt;
        for(int i=31;i>=0;i--){ //Start with MSB.
            cnt=checkBit(res|(1<<i),a,n);//Check if we can set i th bit=1 in the result.
            if(cnt>=2)res|=1<<i;  //If cnt>=2, there exists a pair which will set i th bit in the result(when performed and). 
            //Hence we can update result pattern
        }
        return res;
    }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+5],i;
        for(i=0;i<n;i++)cin>>arr[i];
        cout << maxAND(arr,n)<<endl;
    }
    return 0;
} 