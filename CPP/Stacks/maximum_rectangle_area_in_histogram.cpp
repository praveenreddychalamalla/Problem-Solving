/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-05 
 * @desc Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. (Width =1) 
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define ll long long

long long getMaxArea(long long a[], int n)
{
  stack<int>st;
  ll int area=0,area_max=0;
  /**
   * For every bar store the left limit and right limit.
   * left limit --> 1 + index of the bar which is left to curr_bar and has a height less than curr_bar
   * right limit --> index of the bar which is right to curr_bar and has a height less than curr_bar - 1.
  */
  vector<int> left(n),right(n);
  for(int i=0;i<n;i++){ //Fill left
      if(st.empty()){
          left[i]=0; // No bar has a height less than curr_bar in the left side of it. Hence limit=0
          st.push(i);
      }
      else{
          while(!st.empty() and a[i]<=a[st.top()] )  // Pop until stack is empty or you get an index of bar whose height is less than curr_bar
            st.pop();
          left[i]=st.empty()? 0: st.top()+1;
          st.push(i);
      }
  }
  while(!st.empty()) //Clear Stack
    st.pop();
  for(int i=n-1;i>=0;i--){ //Fill Right
      if(st.empty()){
          right[i]=n-1;// No bar has a height less than curr_bar in the right side of it. Hence limit=n-1
          st.push(i);
      }
      else{
          while(!st.empty() and a[i]<=a[st.top()])st.pop(); // Pop until stack is empty or you get an index of bar whose height is less than curr_bar
          right[i]=st.empty()? n-1: st.top()-1;
          st.push(i);
      }
  }
  for(int i=0;i<n;i++){
      area=a[i]*(right[i]-left[i]+1);
      area_max=max(area_max,area);
  }
  return area_max;
  
}
void solve(){
   int n;
   cin>>n;
   ll int a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   cout<<getMaxArea(a,n);
}
int main() {
    solve();
	return 0;
}
