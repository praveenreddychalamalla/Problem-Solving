/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-15
 * @desc Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
 *       Note: Window size varies from 1 to the size of the Array.
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include <bits/stdc++.h>
using namespace std;

vector <int> maxOfMin(int a[], int n){

    stack<int>st;
    vector<int>left(n,0),right(n,0); //for every element store the indices of its previous smaller element and its next smaller element
    for(int i=0;i<n;i++){
        while(!st.empty()&&a[i]<=a[st.top()])st.pop();
        if(st.empty()){
            left[i]=-1;
            st.push(i);
        }
        else{
            left[i]=st.top();
            st.push(i);
        }
    }
    while(!st.empty())st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&a[i]<=a[st.top()])st.pop();
        if(st.empty()){
            right[i]=n;
            st.push(i);
        }
        else{
            right[i]=st.top();
            st.push(i);
        }
    }
    vector<int>res(n,0);
    for(int i=0;i<n;i++){
        int j=right[i]-left[i]-1; //length of window in which a[i] is minimum 
        res[j-1]=max(res[j-1],a[i]); //res[i] will contain the max of of all minimums of windows with size i+1
    }
    for(int i=n-2;i>=0;i--){
        res[i]=max(res[i],res[i+1]); //Fill remaining positions
    }
    return res;
    
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector <int> res = maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}