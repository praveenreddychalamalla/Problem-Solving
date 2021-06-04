/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-02 
 * @desc Count the Number of Triangles Possible. Time Complexity - O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;

bool isTrianglePossible(int a, int b,int c){
    return(a+b>c && a+c>b && b+c>a);
}
int findNumberOfTriangles(int a[], int n)
{
    int cnt=0,i,l,r;
    sort(a,a+n);
    for(i=n-1;i>=1;i--){
        l=0;
        r=i-1;
        while(l<r){
            if(isTrianglePossible(a[l],a[r],a[i])){
                cnt+=r-l; // As array is sorted, you can form triangles with a[k],a[r],a[i] for l<=k<r
                r--;
            }
            else l++;
        }
    }
    return cnt;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends