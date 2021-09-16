/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-14
 * @desc Stock Span Problem
 */

//Time Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;

vector <int> calculateSpan(int price[], int n)
{
    stack<int>st;

    /**For every day, store the left limit. 
     * left limit --> 1 + index of the day which is previous (Left) to curr_day and has stock price greater than curr_day
     */
    int left[n]={0};
    vector<int>v;
    for(int i=0;i<n;i++){ //Fill Left
        if(st.empty()){
            left[i]=0; // No day has stock price greater than curr_day in the previous days. Hence Left limit=0
            st.push(i);
        }
        else{
            while(!st.empty()&& price[st.top()]<=price[i])st.pop();  // Pop until stack is empty or you get an index of day, whose stock price is greater than stock price of curr_day
            if(st.empty())left[i]=0;
            else left[i]=st.top()+1;
            st.push(i);
        }
    }
    for(int i=0;i<n;i++){
        v.push_back(i-left[i]+1); //Span
    }
    return v;
}
/* The problem boils down to finding the closest greater element's index to the left. Similar to finding next greater element problem

	vector <int> calculateSpan(int a[], int n){
	   vector<int>span(n);
	   stack<int>st;
	   for(int i=0;i<n;i++){
		   while(!st.empty()&& a[i]>=a[st.top()])st.pop();
		   if(st.empty()){
			   st.push(i);
			   span[i]=i+1; //No index as such, hence span is i+1
		   }
		   else{
			   span[i]=i-st.top();
			   st.push(i);
		   }
	   }
	   return span;
}
*/
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		vector <int> span = calculateSpan(a, n);

		for(i=0;i<n;i++){
			cout<<span[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}