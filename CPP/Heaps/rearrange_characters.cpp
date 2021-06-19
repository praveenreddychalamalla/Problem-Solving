/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-14
 * @desc Given a string S with repeated characters, rearrange characters in the string such that no two adjacent characters are same. Return "-1" if not possible 
 */

//Time Complexity - O(nlogn), Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

string rearrangeString(string str){
    string res="";
    int n=str.length();

    priority_queue<pair<int,char>>pq; // Create a Heap of pairs, most frequent character is maintained at top.
    map<char,int>m; 
    
    for(auto c:str)m[c]+=1; //Store Char and frequency to insert into heap
    for(auto e:m)pq.push({e.second,e.first}); //Max heap is constructed using first value of pair (e.second = freq of char, e.first =char)
    
    if(pq.top().first>n/2)return "-1"; //If most frequent character's frequency is more than n/2, we cannot arrange the string as said.
    pair<int,char>prev={-1,'*'}; //Use a dummy prev character, so that we do not pop the same character successively from the heap
    
    while(!pq.empty()){
        pair<int,char> p=pq.top(); 
        pq.pop();
        res+=p.second; //Pop the top most character and add it to result. 
        p.first--;

        if(prev.first>0)pq.push(prev); //If prev characters freq <=0, no use with that character.

        prev=p; //Temporarily move the curr character out of priority queue, so that it is not picked next time.
        
    }
    if(res.length()==n) return res;
    else return "-1";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    string str1=rearrangeString(str);

	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  