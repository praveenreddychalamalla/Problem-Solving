#include <bits/stdc++.h>
using namespace std;
// Function to find maximum product subarray - O(n)
typedef long long ll;
long long maxProduct(int *a, int n) {
	long long prod=a[0],maxVal=a[0],minVal=a[0];
	for(int i=1;i<n;i++){
		if(a[i]<0)swap(maxVal,minVal); //when multiplied by a -ve number min becomes max, and max becomes min
		maxVal=max(ll(a[i]),maxVal*a[i]); //Similar to Kadanes algo.
		minVal=min(ll(a[i]),minVal*a[i]);
		prod=max(prod,maxVal);
	}
	return prod;	
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) 
            cin >> arr[i];
        auto ans = maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
} 