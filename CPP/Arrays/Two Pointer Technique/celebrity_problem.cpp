/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-17
 * @desc A celebrity is a person who is known to all but does not know anyone at a party. 
 *       If you go to a party of N people, find if there is a celebrity in the party or not.
 *       Given a NxN matrix representing people, a[i][j]=1 means person i knows person j and always a[i][i]=0 
 */

//Time Complexity - O(n), Space Complexity- O(1)
#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& a, int n) {

    int i=0,j=n-1,person=-1; 
    while(i<j){
        if(a[i][j]==1){ //Person i knows j, hence person i cannot be celebrity and potential candidate is j. 
            person=j;
            i++; //Eliminate i from search space by incrementing i  
        }
        else{ //Person i does not know j, hence person i is the potential candidate and j is not celebrity
            person=i; 
            j--; //Eliminate j from search space by decrementing j
        }
    }
     //Check if the potential person is known to every one and the potential person does not know anyone
    for(int i=0;i<n;i++)if(a[person][i]==1||(a[i][person]==0 && i!=person))return -1;
    return person;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<celebrity(M,n)<<endl;

    }
}