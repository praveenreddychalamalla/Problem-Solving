/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-26
 * @desc Check if a given binary tree is a BST
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

Node* removekeys(Node* root, int l, int r) {

    if(root){
        root->left=removekeys(root->left,l,r);
        root->right=removekeys(root->right,l,r);
        
        if(root->data<l){
            Node* RChild=root->right;
            delete root;
            return RChild;
        }
        else if(root->data>r){
            Node* LChild=root->left;
            delete root;
            return LChild;
        }
        else return root;
    }
    else return NULL;
}
/*  Memory is not freed

    Node* removekeys(Node* root, int l, int r) {
        if(root){
            if(root->data<l){
                return removekeys(root->right,l,r); //Keys in LST will be outside the range, hence ignore them
            }
            else if(root->data>r){
                return removekeys(root->left,l,r); //Keys in RST will be outside the range, hence ignore them
            }
            else{
                root->left=removekeys(root->left,l,r);
                root->right=removekeys(root->right,l,r);
                return root;
            }
        }
        else return NULL;
    }
*/
Node* insert(Node* root, int key){
    if (root == NULL)
       return new Node(key);
    if (root->data > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
int main()
{
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);

    cout << "Inorder traversal of the given tree is: ";
    inorderTraversal(root);

    root = removekeys(root, -10, 13);

    cout << "\nInorder traversal of the modified tree is: ";
    inorderTraversal(root);

    return 0;
}