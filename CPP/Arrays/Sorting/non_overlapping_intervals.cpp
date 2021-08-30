/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-29
 * @desc Given an array of intervals intervals where intervals[i] = [starti, endi], 
 *       return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 */
#include<bits/stdc++.h>
using namespace std;
static bool comp(vector<int>& x1, vector<int>& x2){
        return x1[0]<x2[0]|| x1[0]==x2[0] && x1[1]>x2[1]; //If two intervals start at same x, make the largest interval to appear first
}
int eraseOverlapIntervals(vector<vector<int>>& a) {
    sort(a.begin(),a.end(),comp);
    int cnt=0,n=a.size(),l=a[0][0],r=a[0][1];
    for(int i=1;i<n;i++){
        int x1=a[i][0],x2=a[i][1];
        if(r<=x1){ //If intervals are non overlapping, update current interval
            l=x1;
            r=x2;
        }
        else if(l==x1){
            r=x2; //Reduce the interval size 
            cnt++;
        }
        else{
            if(x2<r){ //Reduce the interval size 
                l=x1;
                r=x2;
            }
            cnt++;
        }
    }
    return cnt;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector< vector<int> > intervals(n,vector<int>(2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cin>>intervals[i][j];
            }
        }
        auto ans =eraseOverlapIntervals(intervals);
        cout << ans << "\n";
    }
    return 0;
}
