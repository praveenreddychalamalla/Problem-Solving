/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-11-02
 * @desc Given a binary tree and a node called target. 
 *       Find the minimum time required to burn the complete binary tree if the target is set on fire.
 *       It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
 */

//Time Complexity - O(n), Space Complexity - O(Height of tree)

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

class Solution {
  public:
    int res;
    //pair : first value indicates the presence of target node in the subtree, second value is height of subtree / distance from target node
    pair<int,int> burnTree(Node* root,int target){ 
        if(root){
            auto l=burnTree(root->left,target);
            auto r=burnTree(root->right,target);
            if(root->data==target){
                res=max(res,max(l.second,r.second));
                return {1,1}; //Inform the presence of target to the caller (parent node) and initialize the distance from it
            }
            if(l.first==1){ //Target is in LST
                res=max(res,l.second+r.second); //Max distance path could be flowing throgh this node
                return {1,1+l.second}; //Propogate the distance from target node to the parent node
            }
            if(r.first==1){ //Target is in RST
                res=max(res,l.second+r.second); //Max distance path could be flowing throgh this node
                return {1,1+r.second}; //Propogate the distance from target node to the parent node
            }
            return {0,1+max(l.second,r.second)}; //Just propogate the height of subtree
        }
        else return {0,0}; 
    }
    int minTime(Node* root, int target) {
        res=INT_MIN; //Intialize res to INT_MIN, we are trying to find the distance between target node and farthest node away from target
        //finding max distance between target node and any other node in the tree
        burnTree(root,target);
        return res;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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


 // } Driver Code Ends
//User function Template for C++



// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Drive