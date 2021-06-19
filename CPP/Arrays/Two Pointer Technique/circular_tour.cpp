/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-16
 * @desc Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
 *       Assume for 1 litre petrol, the truck can go 1 unit of distance. 
 *       petrolPump.petrol = amount of petrol that petrol pump has.
 *       petrolPump.distance = Distance from that petrol pump to the next petrol pump.
 */
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


int tour(petrolPump p[],int n) //Given an array of petrolPumps
{
    int start=0,end=1;
    int fuel =p[start].petrol-p[start].distance;

    while(end!=start || fuel<0){ //end==start indicates that tour is finished
       
        while(fuel<0 && start!=end){
            fuel-=p[start].petrol-p[start].distance; //Remove the weight of starting petrol pump
            start=(start+1)%n; //Increment starting point
            if(start==0)return -1; //Again, if we hit 0 as start, then there is no such tour possible
        }
        fuel+=p[end].petrol-p[end].distance; 
        end=(end+1)%n;
    }
    return start;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
