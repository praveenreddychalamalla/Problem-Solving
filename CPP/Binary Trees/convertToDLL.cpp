 /**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-02
 * Given a special binary tree having random pointers along with the usual left and right pointers. Clone the given tree.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};


Node *prev1, *head; //Using prev variable in global space (when default namaspace is set to std) conflicts with std:: prev() function

void convertToDLL(Node* root){ //Inorder
    if(root){
        convertToDLL(root->left);

        if(!prev1){
            head=root;
            prev1=root;
        }
        else{
            prev1->right=root;
            root->left=prev1;
            prev1=root;
        }
        convertToDLL(root->right);
    }
}

Node * bToDLL(Node *root)
{
    head=NULL;
    prev1=NULL;
    convertToDLL(root);
    return head;
}