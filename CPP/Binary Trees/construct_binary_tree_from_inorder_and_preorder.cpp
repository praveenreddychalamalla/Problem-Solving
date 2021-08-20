/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-12
 * @desc Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 
 */

//Time Complexity - O(n*n), Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


Node* constructTree(int in[],int pre[],int& k,int start,int end){
    if(start>end)return NULL;
    Node* root=new Node(pre[k++]); //Pick element from preorder array and create a node. Increment the traversal pointer
    if(start==end)return root; //If the current node has no children i.e.., Leaf Node, Simply return this Node.
    int index=-1;
    for(int i=start;i<=end;i++){ //Search for the picked element index in the inorder array
        if(pre[k-1]==in[i]){
            index=i;
            break;
        }
    }
    root->left=constructTree(in,pre,k,start,index-1);   // Call to build left subtree from inorder array with boundaries start to index-1
    root->right=constructTree(in,pre,k,index+1,end);     // Call to build right subtree from inorder array with boundaries index+1 to end
    return root;
}
Node* buildTree(int in[],int pre[], int n){
    int k=0; //Traverses the preOrder array one by one
    return constructTree(in,pre,k,0,n-1);
    
}

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}