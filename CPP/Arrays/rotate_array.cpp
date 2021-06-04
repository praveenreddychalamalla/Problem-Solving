/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-03
 * @desc Rotate Array - Juggling Algorithm - Move the elements in sets.
*/

// Time Complexity - O(n), Space Complexity - O(1)
#include<bits/stdc++.h>
using namespace std;

//Function to rotate an array by d elements in counter-clockwise direction. 
void rotateArr(int a[], int d, int n){
    int k=__gcd(n,d),l=-1,r;  // Divide the n elements into k sets. Move the elements within each set (Cycles)
    for(int i=0;i<k;i++){
        l=i;              // Start with left (l) =i
        int temp=a[i];    //Store the element in a temporary variable, It will be over written
        while(1){
            r=(l+d)%n; // Calculate the position of element (r) which has to come and sit in place of a[l] 
            if(r==i) break;  //Reached the starting point, which implies that cycle is finished.
            a[l]=a[r];
            l=r; // Point l to r and find next position of r
        }
        a[l]=temp; //Next position of element which has to come into a[l] is i, but that location is overwritten, hence assign the preserved value.
    }
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, d;
	    cin >> n >> d;
	    
	    int arr[n];
	    for(int i = 0; i < n; i++) cin >> arr[i];
	    rotateArr(arr, d,n);
	    
	    for(int i =0;i<n;i++) cout << arr[i] << " ";
	    cout << endl;
	}
	return 0;
}  