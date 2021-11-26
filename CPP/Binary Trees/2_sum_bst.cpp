/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-26
 * @desc Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum.
 */
//Time Complexity - O(n), Space Complexity - O(height)

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int key){
        data=key;
        left=NULL;
        right=NULL;
    }
};
//Similar to two pointer approach - Perform Iterative Traversals on the tree in inOrder and reverseInorder parallely and move the pointers accordingly
int isPairPresent(struct Node *root, int target){

    stack<pair<Node*,bool>>s1,s2;
    s1.push({root,1});
    s2.push({root,1});
    int x=-1,y=-1;
    int flag=1;
    while(flag==1){
        while(x==-1){
            auto l=s1.top();
            s1.pop();
            if(l.second){ //Normal Inorder
                if(l.first->right)s1.push({l.first->right,1});
                s1.push({l.first,0});
                if(l.first->left)s1.push({l.first->left,1});
            }
            else x=l.first->data;
        }
        while(y==-1){ //Reverse Inorder
            auto r=s2.top();
            s2.pop();
            if(r.second){
                if(r.first->left)s2.push({r.first->left,1});
                s2.push({r.first,0});
                if(r.first->right)s2.push({r.first->right,1});
            }
            else y=r.first->data;
        }
        if(x+y==target)flag=0;
        else if(x+y>target) y=-1; //Move right pointer - Resume Reverse Inorder
        else x=-1; //Move left pointer - Resume Inorder
        if(s1.empty()||s2.empty())flag=-1;
    }
    return !flag;
}
int main(){
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    int target = 33;
    if (isPairPresent(root, target) == false)
        cout << "\nNo such values are found\n";
    else cout<<"Found"<<endl;
    return 0;
}