/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-09
 * @desc Find the inorder successor of a given node
 */

//Time Complexity - O(log n), Space Complexity - O(log n)
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* minInRightSubTree(Node* root){
        while(root->left)root=root->left;
        return root;
    }
Node * inOrderSuccessor(Node *root, Node *target)
{   
    if(!target||!root)return NULL;
    if(target->right){
        return minInRightSubTree(target->right);
    }
    else{
        Node *successor=NULL;
        while(root && root!=target){
            if(target->data<root->data){ //find deepest ancestor, for which current node will be in its left sub tree
                successor=root;
                root=root->left;
            }
            else root=root->right;
        }
        return successor;
    }
}
/*  
    Time Complexity - O(log n), Space Complexity - O(log n)
    Node * inSuc;
    void traverse(Node *root,Node* target, Node* &next){ //Perform Reverse InOrder, by storing previous node
        if(root){
            if(!inSuc)traverse(root->right,target,next);
            if(root==target){
                inSuc=next;
                return;
            }
            next=root;
            if(!inSuc)traverse(root->left,target,next);
            
        }
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* next=NULL;
        inSuc=NULL;
        traverse(root,x,next);
        return inSuc;
    }
*/