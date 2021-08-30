/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-29
 * @desc Bottom View of Binary Tree
 */

/* Bottom view from left to righ:.
    A node is included in bottom view if it can be seen when we look at the tree from bottom.

                        20
                      /    \
                    8       22
                  /   \       \
                 5     3       25
                     /   \      
                   10     14

    For the above tree, the bottom view is 5 10 3 14 25.
    If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                        20
                      /    \
                    8       22
                  /   \    /   \
                5      3 4     25
                      /   \      
                    10     14

    For the above tree the output should be 5 10 4 14 25.
*/


//Time Complexity - O(n), Space Complexity - O(n)
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node{
    int data;
    Node* left;
    Node* right;
};

int y;
map<int,map<int,int>>m;
void preOrder(Node* root, int x){
    if(root){
        m[x][y]=root->data; //Store vertical Order Traversal in a map with x and y coordinates.( y is depth from root node). If same x,y coordinates ==>later one is preserved
        y++;
        preOrder(root->left,x-1);
        preOrder(root->right,x+1);
        y--;
    }
}
vector <int> bottomView(Node *root) {
    m.clear();
    y=0;
    preOrder(root,0);
    vector<int>v;
    for(auto e: m){
/** For a given x, on the vertcial line passing through that x, 
 *  take the last node on the vertical line i.e., node with greatest depth will be close to bottom, which covers all nodes above it.
 */
        int x=e.first;
        auto it=m[x].end(); 
        it--;
        v.push_back(it->second);
    }
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


vector <int> bottomView(Node *root);

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
        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


  // } Driver Code Ends