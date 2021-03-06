/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-21
 * @desc Given an integer N, find its factorial.(N<=1000)
 */

//Time Complexity - O(n^2), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int>&res, int n){
    int carry=0,prod=0;
    int l1=res.size(),i=0;
    while(i<l1){
        prod=res[i]*n+carry;
        res[i]=prod%10;
        carry=prod/10;
        i++;
    }
    /**Redundant - Wont execute : i<l1 ==> carry becomes 0**/
    while(carry){
        res[i++]=carry%10;
        carry/=10;
    }
}
vector<int> factorial(int n){
    double d=0;
    for(int i=1;i<=n;i++) d+=log10(i);
    int l=d+1;
    vector<int>res(l,0),temp;
    res[0]=1;
    for(int i=2;i<=n;i++){
        multiply(res,i);
    } 
    //Extract number from res which is in different representation 
    reverse(res.begin(),res.end());
    int i=0;
    while(i<l){
        if(res[i]>0)break;
        i++;
    }
    while(i<l)temp.push_back(res[i++]);
    return temp;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> result = factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
} 