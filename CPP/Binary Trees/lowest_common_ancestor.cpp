/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-01
 * @desc Given a Binary Tree with all unique values and two nodes value n1 and n2. 
 *       The task is to find the lowest common ancestor of the given two nodes. 
 *       We may assume that either both n1 and n2 are present in the tree or none of them is present. 
 */

//Time Complexity - O(n), Space Complexity - O(Height of tree)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
 Node* lca(Node* root ,int n1 ,int n2 ){
    if(!root)return NULL;
    if(root->data==n1||root->data==n2)return root; //if a key is ancestor of other, then the ancestor key becomes LCA
    Node* leftLCA=lca(root->left,n1,n2);
    Node* rightLCA=lca(root->right,n1,n2);
    if(leftLCA&&rightLCA)return root; //One key is in LST and one key is RST ==> Current node is LCA
    return leftLCA?leftLCA:rightLCA; 
}
/*  If the tree is BST : TC = O(Height of tree)

    Node* LCA(Node *root, int n1, int n2){
    if(!root)return NULL;
    if(root->data==n1||root->data==n2)return root;

    if(n1<root->data && n2<root->data) return LCA(root->left,n1,n2);
    if(n1>root->data && n2>root->data) return LCA(root->right,n1,n2);
    
    return root;
}
*/

/*  Time Complexity - O(n) 2 Traversals, Space Complexity - O(Height of tree) (But extra space for arrays and map used)

    bool flag;
    void getPath(Node* root,int x,stack<Node*>&s){
        if(root){
            s.push(root);
            if(root->data==x){
                flag=1;
                return;
            }
            if(!flag)getPath(root->left,x,s);
            if(!flag)getPath(root->right,x,s);
            if(!flag)s.pop();
        }
    }
    Node* lca(Node* root ,int n1 ,int n2 ){
        stack<Node*>s1,s2;
        flag=0;
        getPath(root,n1,s1);
        flag=0;
        getPath(root,n2,s2);
        unordered_map<Node*,int>m;
        while(!s2.empty()){
            m[s2.top()]++;
            s2.pop();
        }
        while(!s1.empty()){
            if(m[s1.top()])return s1.top();
            s1.pop();
        }
        Node *lca=new Node();
        lca->data=-1;
        lca->left=NULL;
        lca->right=NULL;
        return lca;
    }

*/
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        cout<<lca(root,a,b)->data<<endl;
    }
    return 0;
}