/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-15
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

unordered_map<Node*,Node*>m;
Node* buildTree(Node* root){
    if(!root) return NULL;
    Node* temp=new Node(root->data);
    m[root]=temp;
    temp->left=buildTree(root->left);
    temp->right=buildTree(root->right);
    return temp;
}

void setRandomPointers(Node* root1, Node* root2){
    if(!root1 && !root2) return ;
    root2->random=m[root1->random];
    setRandomPointers(root1->left,root2->left);
    setRandomPointers(root1->right,root2->right);
}
Node* cloneTree(Node* tree)
{
    m.clear();
    Node *root1=tree;
    Node *root2=buildTree(root1);
    setRandomPointers(root1,root2);
    return root2;
}

int checkcloned(Node* a, Node *b)
{
	if ((a == NULL and b == NULL))
		return 1;

	if (a != NULL && b != NULL)
	{
		int t = (a->data == b->data && checkcloned(a->left, b->left) && checkcloned(a->right, b->right));

		if (a->random != NULL && b->random != NULL)
			return (t && a->random->data == b->random->data);
		if (a->random == b->random)
			return t;

		return 0;
	}

	return 0;

}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}



int main(){
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }


     }
     Node *t = cloneTree(root);
     if(t==root)
        cout<<0<<endl;
     else
     cout<<checkcloned(root,t);
     cout<<"\n";
  }
  return 0;
}
