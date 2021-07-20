/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-17
 * @desc Find the no.of palindromes present between 1 to n (both inclusive)
 */

/**
 * Even Number of digits:
 * 
 * How many palindromes are there between 1 and 12345678?
 * If you take the front half ("prefix") of the number, i.e. 1234, you can use that to estimate the number of palindromes. 
 * 
 * Each number between 1 and 1234 can "generate" two palindromes: one with the last digit not repeated ,and one with all digits repeated.
 * Example : Take the number 27. This number can generate 2 palindromic numbers - 272 (without repeating last digit of 27) and 2772 (repeating last digit of 27)
 * 
 * Hence all numbers from [1 - 1234] generates 1234*2 palindromes and generated palindromes are less than 12345678. 
 * 
 * However, there are also some palindromes that are missing. These are generated by prefixes greater than 1234. 
 * For each of the prefixes from 1235 to 9999, there is another palindrome that should be counted. 
 * 
 * Example: Take the number 2345 which is between [1235-9999]. This number generates 2 palindromic numbers - 2345432 ,23455432
 *          2345432 should be counted bcoz it is less than 12345678 and 23455432 should not be counted bcoz it is greater than 12345678.
 * 
 * Hence No.of Palindromes= prefix*2 + (10^prefixLength-1-prefix)
 * 
 * 
 * 
 * 
 * Odd Number of digits:
 * 
 * How many palindromes are there between 1 and 123456789?
 * Prefix = 12345 (rounded)
 * All numbers from 1 to 12345 generates 12345*2 palindromes 
 * 
 * But Some of the prefix*2 palindromes generated are not valid because they are larger than the original number. Example - 1234554321
 * All of the prefixes from [10000 - 12345] generate an extra prefix that is too large. 
 * So there is an adjustment to subtract from the count which is equal to prefix - 10^(prefixLength-1) + 1.
 * 
 * Hence No.of Palindromes= prefix*2 -(prefix-(10^(prefixLength-1))+1)
 * i.e., prefix*2 + 10^(prefixLength-1)-1-prefix     which is equivalent to above except 10 raised to prefixlength-1.
 * 
 * 
 * Note: For both the cases, Sometimes you need to subtract one from the prefix 
 * because the palindrome it generates is less than the original number. 
 * For example, for 12345678, 1234 is the correct prefix to use because 12344321 is less than 12345678. 
 * But if the original number were 12340000, then 1234 would be too high because 12344321 is greater than 12340000.
 * So you would use 1233 as prefix instead of 1234.
*/

//Time Complexity - O(logn)
#include<bits/stdc++.h>
using namespace std;

long long power(long long a, long long n){
  if(n==0)return 1;
  long long res=1;
  while(n--)res*=a;
  return res;
}

long long constructPalindrome(long long prefix,int d){
  string s1=to_string(prefix),s2;
  if(d%2==0)s2=s1;
  else s2=s1.substr(0,d/2);
  reverse(s2.begin(),s2.end());
  return stoll(s1+s2);
}

long long numberOfPalindromes(long long n){
  long long d=1+log10(n),x,prefix,m;
  x=d/2; //prefix length
  prefix=n/power(10,x);
  m=constructPalindrome(prefix,d);
  if(n<m)prefix--;
  return prefix*2+power(10,x)-prefix-1; //Both odd and even cases are handled
}

int main() {

  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      cout<<numberOfPalindromes(n)<<endl;
  }
  return 0;
}
