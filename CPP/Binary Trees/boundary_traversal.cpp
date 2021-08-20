/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-21
 * @desc Find the boundary traversal of the tree in anti-clockwise direction starting from the root.
 */
//Time Complexity - O(n), Space Complexity - O(log n)
#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node{
    int data;
    Node* left;
    Node* right;
};

void leftBoundary(Node *root, vector<int>& v){
        if(!root)return ;
        if(root->left){
            v.push_back(root->data); //Push the data into vector before calling the function  on current_node->left
            leftBoundary(root->left,v);
        }
        else if(root->right){ //If the node has no left child and has a right child, left boundary continues in right sub tree
            v.push_back(root->data); //Push the data into vector before calling the function  on current_node->right
            leftBoundary(root->right,v);
        }
        //Left most node is not inserted
}

void rightBoundary(Node *root, vector<int>& v){
    if(!root)return ;
    if(root->right){
        rightBoundary(root->right,v); //Call the function current_node->right before pushing the data into vector, because the right boundary has to be inserted from bottom to top
        v.push_back(root->data);
    }
    else if(root->left){ //If the node has no right child and has a left child, then right boundary conitnues in left sub tree
        rightBoundary(root->left,v); //Call the function current_node->left before pushing the data into vector, because the right boundary has to be inserted from bottom to top
        v.push_back(root->data);
    }
    //Right most node is not inserted
}

void leafNodes(Node *root,vector<int>& v){
    if(root){
        leafNodes(root->left,v);
        if(!root->left&&!root->right)v.push_back(root->data); //Leaf node
        leafNodes(root->right,v);
    }
}

vector <int> printBoundary(Node *root){

    vector<int>v;
    if(!root) return v;
    v.push_back(root->data);
    leftBoundary(root->left,v);
    leafNodes(root,v);
    rightBoundary(root->right,v);
    return v;
    
}

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

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
} 