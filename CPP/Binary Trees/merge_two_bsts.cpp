/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-22
 * @desc Given two BSTs, return elements of both BSTs in sorted form.
 */

//Time Complexity - O(M+N) (M,N- Sizes of two binary search trees), Space complexity - O(height(bst1)+height(bst2)).
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

void inorder(Node* root,vector<int>& v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
}

//Function to return a list of integers denoting the node values of both the BST in a sorted order.
vector<int> merge(Node *root1, Node *root2){ //Iterative inorder traversal
    vector<int>v;
    if(!root1 && !root2)return v;    //If both bsts are empty , return empty vector.

    else if(root1 && !root2){    //If bst2 is empty, perform inorder on bst1
        inorder(root1,v);
    }

    else if(!root1 && root2){    //If bst1 is empty, perform inorder on bst2
        inorder(root2,v);
    }
    else{ 
        stack<Node*>s1,s2;
        while(root1||!s1.empty()||root2||!s2.empty()){

            if(root1||root2){ // Reach the leftmost node of both BSTs and push ancestors of leftmost nodes into stack s1 and s2 respectively 
                if(root1){
                    s1.push(root1);
                    root1=root1->left;
                }
                if(root2){
                    s2.push(root2);
                    root2=root2->left;
                }
            }

            else{
                if(s1.empty()){ //If s1 is empty, perform inorder on remaining bst2 and return
                    while(!s2.empty()){
                        root2=s2.top(); // Left of curr node is already explored and hence make left child of current node as NULL before calling inorder on current node.
                        s2.pop();
                        root2->left=NULL;
                        inorder(root2,v);
                    }
                    return v;
                }
                if(s2.empty()){ //If s2 is empty, perform inorder on remaining bst1 and return
                    while(!s1.empty()){
                        root1=s1.top(); //Left of curr node is already explored and hence make left child of current node as NULL before calling inorder on current node.
                        s1.pop();
                        root1->left=NULL;
                        inorder(root1,v);
                    }
                    return v;
                }
                Node* x=s1.top(); 
                Node* y=s2.top();
                if(x->data<y->data){ 
                    v.push_back(x->data);
                    root1=x->right; //Explore the right child of node that is going to be popped off
                    s1.pop();
                    root2=NULL;
                }
                else{
                    v.push_back(y->data);
                    root2=y->right;//Explore the right child of node that is going to be popped off
                    s2.pop();
                    root1=NULL;
                }
            }
        }
    }
    return v;
}



// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}






int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
   }
   return 0;
}  