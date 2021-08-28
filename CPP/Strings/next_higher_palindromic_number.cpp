/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-27
 * @desc Given a palindromic number N in the form of string. 
 *       The task is to find the smallest palindromic number greater than N using the same set of digits as in N.
 */
#include <bits/stdc++.h>
using namespace std;

string nextPalin(string s) { 
    int n=s.length();
    if(n<=3)return "-1"; //You cannot generate any other palindrome with same numbers, if length of string <=3 . "1","22","313"
    
    //Divide the palindrome into two halfs 1st half and 2nd half
    int l=n/2-1,r=n/2+1,i,j; 
    if(n%2==0)r--;
    //l points to right end in the 1st half of palindrome, r points to left end in the 2nd half of palindrome i.e., s[l]=s[r]
    //i traverses from right to left in the 1st half and j traverses from left to right in the 2nd half
    for(i=l-1,j=r+1;i>=0;i--,j++){ //Traverse from right to left in the first half and find the index at which you get a dip i.e., s[i]<s[i+1]
        if(s[i]<s[i+1])break;
    }

    if(i<0) return "-1"; // No dip found . Example - "543345" : First half = "543" decreasing sequence from left to right => You cannot generate any other higher number with same digits
    
    int k=i+1; //Now find the index of the number which is greater than s[i] and smallest in the range [i+1,l]
    for(int j=i;j<=l;j++){
        if(s[j]>s[i]&&s[j]<s[k])k=j;
    }
    swap(s[i],s[k]); 
    swap(s[r+l-k],s[j]);//Swap the correspoing elements in the right half to hold palindromic property
    sort(s.begin()+i+1,s.begin()+l+1);//sort the numbers in ascending order in the range [i+1,l] so as to avoid forming other higher palindromes
    sort(s.begin()+r,s.begin()+j,greater<int>()); //sort the numbers in descending order in the range [r,j-1] so as to hold palindrome property
    return s;
    
}
int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << nextPalin(s) << endl;
    }
    return 0;
} 