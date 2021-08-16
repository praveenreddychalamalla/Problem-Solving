/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-22
 * @desc Consider a big party where N guests came to it and a log register for guest’s entry and exit times was maintained. 
 *       Find the minimum time at which there were maximum guests at the party. 
 *       Note: entries in the register are not in any order.
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> findMaxGuests(int Entry[], int Exit[], int n){
    int res=0,pepl=0,t=0;
    vector<int>v;
    sort(Entry,Entry+n); //Sort both the entry times and exit times
    sort(Exit,Exit+n);
    int i=0,j=0; //i points to entry time, j points to exit time
    while(i<n&&j<n){
        if(Entry[i]<=Exit[j]){//If curr entry time is less than or equal to exit time pointed by j, a person has arrived before a person leaving, whose exit time is pointed by j, hence current people increases by 1
            pepl+=1;
            if(pepl>res){
                t=Entry[i];
                res=pepl;
            }
            i++; //Increment entry pointer
        }
        else{ //If curr entry time is more than time pointed by j, a person leaves before the arrival of a person, whose entry time is pointed by i, hence current people decreases by 1
            pepl-=1;
            j++; //Increment exit pointer
        }
    }
    v.push_back(res);
    v.push_back(t);
    return v;
}


 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];

	    vector<int> p =findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
} 