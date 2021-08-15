/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-12
 * @desc Construct Binary Tree (Complete) from given PreOrder and an array which indicates corresponding node of PreOrder array is a Leaf Node or Non Leaf Node
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

//Construct by Traversing in PreOrder Manner ):-
void preOrder(Node* root, int n, int& i, int pre[], char preLN[]){
    if(preLN[i]!='L'){ //If current node is not a leaf node
        i++;
        root->left=new Node(pre[i]);
        preOrder(root->left,n,i,pre,preLN);
        i++;
        root->right=new Node(pre[i]);
        preOrder(root->right,n,i,pre,preLN);
    }
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    Node* root=new Node(pre[0]);
    int i=0;
    preOrder(root,n,i,pre,preLN);
    return root;
}
void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}
