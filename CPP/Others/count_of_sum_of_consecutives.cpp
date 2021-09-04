/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-02
 * @desc Given a number N, the task is find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.
 */

//Time Complexity - O(sqrt(n)), Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;
/* x + (x+1) + (x+2) + ....... + (x+k) = n ==> (K+1)*x + (k*(k+1))/2 =n */
int getCount(int n) {
    int cnt=0;
    long long k=1;
    while(k*(k+1)<2*n){  
        double x=(1.0*n)/(k+1)-k/2.0;
        if(x==(int)x)cnt++;
        k++;
    }
    return cnt;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        cout << getCount(N) << endl;
    }
    return 0;
}  