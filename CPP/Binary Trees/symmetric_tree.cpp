/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-10-23
 * @desc Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.
 */

//Time Complexity - O(n), Space Complexity - O(height of tree)

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool checkSymmetry(Node *node1, Node *node2){
    if(!node1&&!node2)return true;
    if(node1 && node2){
        if(node1->data==node2->data){
            return (checkSymmetry(node1->left,node2->right)&&
                    checkSymmetry(node1->right,node2->left));
        }
        else return false;
    }
    else return false;
}
bool isSymmetric(struct Node* root){   
    if(!root)return true;
    return checkSymmetry(root->left,root->right);
}
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        if(isSymmetric(root)){
            cout<<"True"<<endl;
        }
        else{ 
            cout<<"False"<<endl;
        }
    }
    return 0;
}