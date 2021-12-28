/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-13
 * @desc Given an array arr[] of size, N. Find the subarray with maximum XOR. 
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include<bits/stdc++.h> 
using namespace std; 

struct TrieNode{
    int val; //Only used in leaf nodes. Value obtained when traversed from root to leaf is stored
    TrieNode *next[2];
    TrieNode(){
        val=0;
        next[0]=NULL;
        next[1]=NULL;
    }
};

void insert(TrieNode *root,int pre_xor){
    TrieNode *curr=root;
    int x=pre_xor;
    //Start from MSB, insert all the bits of pre_xor into Trie
    for(int i=31;i>=0;i--){ 
        int bit=x&(1<<i)?1:0; //Check if ith bit is set. If ith bit is set go to right, else goto left
        if(curr->next[bit]==NULL) //Create a new node if needed.
            curr->next[bit]=new TrieNode();
        curr=curr->next[bit]; 
    }
    curr->val=x; //Store value at leaf
}

int computeMaxXor(TrieNode* root,int pre_xor){ //Any leaf node contains xor value of subarray [0,k]  (k<=n-1)
    TrieNode *curr=root;
    int x=pre_xor;
    for(int i=31;i>=0;i--){ 
        int bit=x&(1<<i)?1:0;
        if(curr->next[1-bit]!=NULL)  // Traverse Trie, first look for a prefix that has opposite bit 
            curr=curr->next[1-bit];
        else if(curr->next[bit]!=NULL) // If there is no prefix with opposite bit, then look for same bit. 
            curr=curr->next[bit];
    }
    return (curr->val)^x; //required subarray will be from the index where leaf value  obtained (pre_xor value computed before i.e., xor value of some subarray) to curr index
}
int maxSubarrayXOR(int n, int a[]){    
    TrieNode *root=new TrieNode();
    insert(root,0);
    int res=INT_MIN,pre_xor=0;
    for(int i=0;i<n;i++){
        pre_xor=a[i]^pre_xor;
        insert(root,pre_xor);
        res=max(res,computeMaxXor(root,pre_xor));
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

        cout << maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 