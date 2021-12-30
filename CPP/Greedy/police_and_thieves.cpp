/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-29
 * @desc Find the maximum no.of thieves caught by police
 */

//Time Complexity - O(n), Space Complexity - O(n) 
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int catchThieves(char a[], int n, int k) {
        queue<int>q1,q2;//q1 keeps track of idle police, q2 keeps track of idle thieves
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]=='P'){ //If current person is Police, check if he can catch any available thieves
            // If distance between current police and the theif at the front of the queue is more than k, the thief cannot be caught by any police here after (distance will be more than k)
                while(!q2.empty() && abs(q2.front()-i)>k)q2.pop();  
                if(!q2.empty()){ //There is some theif, who can be caught by current police
                    cnt++;
                    q2.pop();
                }
                else q1.push(i); //Push police into idle queue (q1)
            }
            //If current person is Theif, check if he can be caught by any available police
            else{ 
            // If distance between current theif and the police at the front of the queue is more than k, the police man at the front of q1 will not be able to catch any theif here after (distance will be more than k) 
                while(!q1.empty() && abs(q1.front()-i)>k)q1.pop();
                if(!q1.empty()){ //There is some police, who can catch this theif
                    cnt++;
                    q1.pop();
                }
                else q2.push(i); //Push theif into idle queue (q2)
            }
            
        }
        return cnt;
    }
};


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 