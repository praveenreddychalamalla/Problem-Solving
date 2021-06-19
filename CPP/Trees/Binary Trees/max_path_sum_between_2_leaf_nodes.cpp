/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-18
 * @desc Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another leaf node.
 *
 *  Note: A leaf node in this case refers to a node which is connected exactly to one node.
 * 
 *         2
 *        / \
 *       N   1
 *          / \
 *         N   3
 *  Here leaf nodes are nodes with val=2, val=3. Max path sum=5. 
 */

//Time Complexity - O(n), Space Complexity - O(logn)
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int res=INT_MIN;
int computeMaxPathSum(Node* root){
    if(!root)return 0;
    if(!root->left && !root->right) return root->data;
    
    int ls=computeMaxPathSum(root->left);
    int rs=computeMaxPathSum(root->right);

    if(root->left&&root->right){ //If node has 2 children
        res=max(res,ls+rs+root->data); //Update res, if maximum path sum flowing through curr node is large enough
        return max(ls,rs)+root->data; //Propogate the maximum path sum that can be achieved using curr node to the ancestor
    }
    return root->left? root->data+ls:root->data+rs;  //If node has only one child , maximum path sum cannot flow through this node(curr node being root). Hence Propogate the maximum path sum that can be achieved using curr node to the ancestor
}
int maxPathSum(Node* root){ 
    res=INT_MIN;
    if(!root)return 0;
    else{
        int val=computeMaxPathSum(root); 
        return res==INT_MIN?val:res; //res wil not be updated, if skew tree is passed. Hence check and return accordingly.
    }
}

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
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
    cin>>t;
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << maxPathSum(root) << "\n";
    }
    return 0;
}  