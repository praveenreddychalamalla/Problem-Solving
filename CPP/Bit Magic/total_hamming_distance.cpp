/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-19 
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.Assume 32 bit integers
 */
#include<bits/stdc++.h>
using namespace std;

//Time Complexity - O(32*n)
int totalHammingDistance(int a[], int n) {
    int d=0;
    for(int i=0;i<32;i++){ //From 1st bit to 32 nd bit, for every bit position count the no.of 1s and and 0's in the respective position
        int k1=0,k2=0;
        for(int j=0;j<n;j++){ 
            if(a[j]%2)k1++;
            else k2++;
            a[j]>>=1;
        }
        d+=k1*k2; //You have to choose no.s differing in bits in respective positions, no.of ways to choose is k1C1*k2C1. Each pair contributes 1 to the hamming distance from that position
        /**
         * Eg : [8,2,4] ==>   1000
         *                    0010
         *                    0100
         *                   ------
         *             bit pos 0 : 0's =3, 1's=0 ==> No contirbution to Hamming distance
         *             bit pos 1 : 0's =2, 1's=1 ==> contirbution to Hamming distance = 2*1 =2 ( when pair (8,2) is chosen bit pos 1 contributes 1 to hamming distance similary for pair (2,4))
         *             bit pos 2 : 0's =2, 1's=1 ==> contirbution to Hamming distance = 2*1 =2
         *             bit pos 3 : 0's =2, 1's=1 ==> contirbution to Hamming distance = 2*1 =2
         */
    }
    return d;
}
/*  Time Complexity - O(n^2)

    int hammingDistance(int x, int y){
        int n=x^y,cnt=0;
        while(n){
            cnt++;
            n=n&(n-1);
        }
        return cnt;
    }
    int totalHammingDistance(vector<int>& a) {
        int n=a.size(),d=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                d+=hammingDistance(a[i],a[j]);
            }
        }
        return d;
    }
*/
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+5],i;
        for(i=0;i<n;i++)cin>>arr[i];
        cout << totalHammingDistance(arr,n)<<endl;
    }
    return 0;
} 