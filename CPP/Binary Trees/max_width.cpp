/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-06-18
 * @desc Given the root of a binary tree, return the maximum width of the given tree.
 *       The maximum width of a tree is the maximum width among all levels.
 *       The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes),
 *       where the null nodes between the end-nodes are also counted into the length calculation.
 */

//Time Complexity - O(n), Space Complexity - O(n)
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

int res;
void levelOrderTraversal(Node* root){
    queue<pair<Node*,unsigned long long>>q; //Use child child no. as you use for heaps, 2*i+1, 2*i+2 ):-
    
    q.push({root,0});
    while(!q.empty()){
        auto e1=q.front(); //e1 holds the left most node in a level
        int n=q.size();
        while(n--){
            auto temp=q.front();
            q.pop();
            if(temp.first->left)q.push({temp.first->left,2*temp.second+1}); 
            if(temp.first->right)q.push({temp.first->right,2*temp.second+2});

            if(n==0){    //temp now holds the right most node in a level
                res=max(res,(int)(temp.second-e1.second+1));
            }

        }
    }
}
int widthOfBinaryTree(Node* root) {
    res=0;
    levelOrderTraversal(root);
    return res;
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
        cout << widthOfBinaryTree(root) << "\n";
    }
    return 0;
}  