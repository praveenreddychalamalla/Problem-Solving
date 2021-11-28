/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-26
 * @desc You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. 
 *       Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
 */
//Time Complexity - O(n), Space Complexity - O(height)

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node *first, *second, *previous;
void inOrder(Node* root){
    if(root){
        inOrder(root->left);
        if(!previous){
            previous=root;
        }
        else{
            if(previous->data>root->data){
                if(!first){
                    first=previous;
                    second=root;
                }
                else{
                    second=root;
                }
            }
            previous=root;
        }
        inOrder(root->right);
    }
}

void correctBST( struct Node* root ){
    first=NULL;
    second=NULL;
    previous=NULL;
    inOrder(root);
    if(first && second)swap(first->data,second->data);
    return;
}

void printInorder(Node* node){
    if (node == NULL)
        return;
    printInorder(node->left);
    cout <<"  "<< node->data;
    printInorder(node->right);
}

int main(){
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
 
    Node *root = new Node(6);
    root->left        = new Node(10);
    root->right       = new Node(2);
    root->left->left  = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);
 
    cout <<"Inorder Traversal of the original tree \n";
    printInorder(root);
 
    correctBST(root);
 
    cout <<"\nInorder Traversal of the fixed tree \n";
    printInorder(root);
 
    return 0;
}