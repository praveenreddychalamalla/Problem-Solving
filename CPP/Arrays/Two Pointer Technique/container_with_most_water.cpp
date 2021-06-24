/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-22
 * @desc Given n non-negative integers a_1, a_2, ..., a_n  where each represents a point at coordinate (i, a_i)             . ‘ n ‘ vertical lines are drawn such that the two endpoints of line i is at (i, a_i) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 */
#include<bits/stdc++.h>
using namespace std;
int maxArea(int a[],int n) { //Time Complexity - O(n)
   
    int i=0,j=n-1,res=0; //Start with two pointers each pointing to left most and right most lines respectively, because the distance between them is maximum and check for better boundaries if any exist between them.
    while(i<j){
        int area=min(a[i],a[j])*(j-i); //Area between current boundaries
        res=max(area,res);
        //As we want to maximize the area, we move the pointer pointing to line which has less height 
        if(a[i]<a[j])i++; 
        else j--;
    }
    return res;
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
        auto ans = maxArea(arr, n);
        cout << ans << "\n";
    }
    return 0;
} 
