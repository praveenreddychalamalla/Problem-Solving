/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-14
 * @desc Given an array arr[ ] of size N having distinct elements, 
 * find the next greater element for each element of the array in order of their appearance in the array.
 */
#include<bits/stdc++.h>
using namespace std;


 vector<long long> nextLargerElement(vector<long long> a, int n){
    stack<long long>st;
    vector<long long>v(n);
    for(int i=n-1;i>=0;i--){

/**If the current element is greater than element on top of stack, then using the current element as greater element 
 * for the elements which are to the left of it will be optimal because it is more clsoer, hence pop useless elements
 */
        while(!st.empty()&&a[i]>=st.top())st.pop(); 
        if(st.empty()){
            st.push(a[i]);
            v[i]=-1;
        }
        else{
            v[i]=st.top();
            st.push(a[i]);
        }
    }
    return v;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
} 