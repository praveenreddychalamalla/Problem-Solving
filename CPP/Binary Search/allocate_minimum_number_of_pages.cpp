/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-23
 * @desc Allocate minimum number of pages
 */

//Time Complexity - O(nlogn), Space Complexity - O(1)
#include<bits/stdc++.h>
using namespace std;


int findPages(int a[], int n, int students) {
    if(n<students)return -1; //If no.of books are less than no.of students, allocation is not possible
    
    int l=0,r=0,ans=-1;
    for(int i=0;i<n;i++)r+=a[i];
    while(l<=r){
        int m=(l+r)/2;
        int pages=0,cnt=1,flag=1;
        for(int i=0;i<n;i++){
            if(a[i]>m){ //If Pages in any book are more than m, allocating m pages to every one is infeasible, answer lies in right half space
                flag=0;
                break;
            }
            pages+=a[i];
            if(pages>m){
                pages=a[i];
                cnt++;
                if(cnt>students){ //If students required are more, increase the pages, answer lies in right half space
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        cout << findPages(A, n, m) << endl;
    }
    return 0;
}
 