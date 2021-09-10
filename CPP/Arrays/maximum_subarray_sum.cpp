/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-22
 * @desc Maximum subarray sum - Kadanes Algorithm . Sub array cannot be of size zero.
 */
#include<bits/stdc++.h>
using namespace std;


int maxSubArraySum(int a[],int n) { //Time Complexity - O(n)
        int res=a[0],sum=a[0];
        for(int i=1;i<n;i++){
            sum=max(a[i],a[i]+sum);
            res=max(res,sum);
        }
        return res;
}
/* Above is the conscised code of this:

	int maxSubArray(vector<int>& a) {
			int res=INT_MIN,sum=0;
			int n=a.size();
			for(int i=0;i<n;i++){
				sum+=a[i];
				if(sum<0){
					res=max(res,a[i]); //Handles when all the elements are -ve i.e., picks largest element
					sum=0;
				}
				else res=max(res,sum);
			}
			return res;
		}
*/
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) 
            cin >> arr[i];
        auto ans = maxSubArraySum(arr, n);
        cout << ans << "\n";
    }
    return 0;
} 