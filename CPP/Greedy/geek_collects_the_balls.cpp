/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-02
 * @desc Geek Collects the Balls
 *       There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. 
 *       The balls in first road are given in an array a and balls in the second road in an array b. 
 *       The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them. 
 *       Geek starts from the end of the road which has the bucket with a lower number of balls.
 *       Geek can change the road only at a point of intersection ie- a point where buckets have the same number of balls on two roads. 
 *       Help Geek collect the maximum number of balls.
 */

//Time Complexity - O(n), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;

int maxBalls(int n, int m, int a[], int b[]){

    int res=0,i=0,j=0,track1=0,track2=0;

    while(i<n&&j<m){  //Traverse both the arrays to get the intersection points
        if(a[i]<b[j]) track1+=a[i++];  //as array 'a' is sorted and a[i]<b[i], incrementing i would take you to intersection point
        else if(a[i]>b[j]) track2+=b[j++]; //as array 'b' is sorted and a[i]>b[i], incrementing j would take you to intersection point

        else{ //Intersection Point i.e., a[i]==a[j]
            res+=max(track1,track2)+a[i]; //Pick the track which yields maximum balls
            track1=0;track2=0; //Reset Tracks
            int temp=a[i];
            i++;j++;
            while(i<n && temp==a[i])res+=a[i++]; // If there are consective stream of balls with same value as that of intersection point in first road, they can simply be collected.
            while(j<m && temp==b[j])res+=b[j++]; // If there are consective stream of balls with same value as that of intersection point in second road, they can simply be collected.
            /**
             *  n=6,m=7
                a=[1,4,5,8,8,8].
                b=[2,8,8,8,9,9,9].
                At i=3 and j=1, intersection point is obtained with balls= 8.
                Now geek can collect the balls on both roads until balls in buckets are 8 without any problem.
            */
        }
    }
    while(i<n)track1+=a[i++]; //Collect remaining balls if any are left!
    while(j<m)track2+=b[j++]; //Collect remaining balls if any are left!
    res+=max(track1,track2);
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        int a[N], b[M];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];
        
        cout<<maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
} 