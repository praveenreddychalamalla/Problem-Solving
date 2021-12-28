/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-27
 * @desc Given an array arr containing N words consisting of lowercase characters. 
 *       Your task is to find the most frequent word in the array. If multiple words have same frequency, 
 *       then print the word whose first occurence occurs last in the array as compared to the other strings with same frequency.
 */

//Time Complexity - O(n * |s|), Space Complexity - O(n*|s|)

#include<bits/stdc++.h> 
using namespace std; 

struct TrieNode{
    int freq; //strore the frequency
    int index; //Store the first occurance of the word in the array 
    TrieNode* next[26];
    TrieNode(){
        freq=0;
        index=-1;
        for(int i=0;i<26;i++)next[i]=NULL;
    }
};

pair<int,int> insertIntoTrie(TrieNode* root, string s, int i){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(!root->next[s[i]-'a'])root->next[s[i]-'a']=new TrieNode();
        root=root->next[s[i]-'a'];
    }
    root->freq++;
    if(root->index==-1)root->index=i;
    return {root->freq,root->index};
}

string mostFrequentWord(string arr[], int n) {
    int max_freq=0,index=-1;
    string res="";
    TrieNode* root=new TrieNode();
    for(int i=0;i<n;i++){
        pair<int,int>p=insertIntoTrie(root,arr[i],i);

        if(p.first>max_freq){
            max_freq=p.first;
            res=arr[i];
            index=p.second;
        }
        else if(p.first==max_freq){
            if(p.second>index){
                index=p.second;
                res=arr[i];
            }
        }
    }
    return res;
}
int main() { 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        cout << mostFrequentWord(arr,N) << endl;
    }
    return 0; 
} 