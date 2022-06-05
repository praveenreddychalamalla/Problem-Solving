/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-06-05
 * @desc Bubble Sort
 */

#include<bits/stdc++.h>
using namespace std;
//Time Complexity - O(n^2), Space Complexity - O(1)
class Solution
{
    public:
    
    void bubbleSort(int a[], int n)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1])swap(a[j],a[j+1]);
            }
        }
        return;
    }
};