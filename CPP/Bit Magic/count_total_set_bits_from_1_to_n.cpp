/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-12
 * @desc Find the total count of set bits for all numbers from 1 to N(both inclusive).
 */
#include<bits/stdc++.h>
using namespace std;

//Time Complexity - O(logn)
int countSetBits(int n)
{
    int cnt=0;
    if(n==0)return 0;
    int x=(int)(log2(n)); //Get the left most set bit of n.
    while(n){
        // count of all set bits upto nearest 2^x to n (2^x<=n) + No.of numbers from n to 2^x (Both inclusive - Because all these numbers will have set bit in Xth pos)
        cnt+=x*(1<<x-1)+n-(1<<x)+1;  //cnt=cnt  +  x*(2^x)/2  + n-(2^x)+1
        n&=~(1<<x); //Turn off the Left Most Set Bit and find the next Left Most Set Bit in updated n
        
        //Setting x to Left Most Set Bit position of latest n.
        while(n && x>0){
            if(n&1<<x)break; //Check whether x th bit is set in updated n.
            x--;
        }
    }
    return cnt;
    
}

int main()
{
	 int t;
	 cin>>t;
	 while(t--)
	 {
	       int n;
	       cin>>n;
	       cout <<countSetBits(n) << endl;
	  }
	  return 0;
}