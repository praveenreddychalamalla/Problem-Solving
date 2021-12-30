/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-16
 * @desc Max meetings in a room that can be held without overlapping (m1.end<m2.start) given start and end times of meetings
 */

#include <bits/stdc++.h>
using namespace std;
int maxMeetings(int start[], int end[], int n){

    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++) v[i]={end[i],start[i]};
    sort(v.begin(),v.end());
    int cnt=1;
    pair<int,int>prev=v[0];
    for(int i=1;i<n;i++){
        if(v[i].second>prev.first){ //Current meeting's start is greater than prev meeting's end time, allocate room for this meeting
            prev=v[i];
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
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends