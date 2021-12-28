/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-27
 * @desc Given an array arr[] of size, N. Find minimum xor of any 2 elements.
 */

//Time Complexity - O(n), Space Complexity - O(n)

#include<bits/stdc++.h> 
using namespace std; 

struct TrieNode{
    int val;
    TrieNode* next[2];
    
    TrieNode(){
        val=0;
        next[0]=next[1]=NULL;
    }
};

void insertIntoTrie(TrieNode * root, int key){
    TrieNode * trav=root;
    for(int i=31;i>=0;i--){
        int bit=key&(1<<i)?1:0; //current bit
        if(!trav->next[bit])trav->next[bit]=new TrieNode();
        trav=trav->next[bit];
    }
    trav->val=key;
}
int getMinXor( TrieNode* root, int key){
    TrieNode * trav=root;
    for(int i=31;i>=0;i--){
        int bit=key&(1<<i)?1:0; //current bit
        if(trav->next[bit])trav=trav->next[bit]; //If current bit is in prefix, choose the same path , will fetch you the min value
        else if(trav->next[1-bit])trav=trav->next[1-bit];  //If current bit is not in prefix, choose the opposite path 
    }
    return key^(trav->val);
}

int minXORPair(int N, int arr[]){    
    TrieNode* root=new TrieNode();
    insertIntoTrie(root,arr[0]);
    int res=INT_MAX;
    for(int i=1;i<N;i++){
        res=min(res,getMinXor(root,arr[i]));
        insertIntoTrie(root,arr[i]);
    }
    return res;
}

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        cout << minXORPair(N, arr) << endl;
    }
    return 0; 
} 