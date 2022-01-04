/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-12-31
 * @desc We run a preorder depth-first search (DFS) on the root of a binary tree.
 *       At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  
 *       If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
 *       If a node has only one child, that child is guaranteed to be the left child.
 *       Given the output traversal of this traversal, recover the tree and return its root.
 * 
 *  Eg : traversal = "1-2--3--4-5--6--7"        1
 *                                            /   \
 *                                           2     5
 *                                          / \   / \
 *                                         3   4 6   7
 * 
 *      traversal = "1-401--349---90--88"       1
 *                                             /
 *                                            401
 *                                            /  \
 *                                           349  88
 *                                          /
 *                                         90
 * 
 */

//Time Complexity - O(|s|), Space Complexity - O(|height|)

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int getNumber(string &s, int& i){
        string n="";
        int l=s.length();
        while(i<l && s[i]!='-')n+=s[i++];
        if(n=="")return 0; //stoi on empty string throws invalid argument exception
        return stoi(n);
    }
    TreeNode* recoverFromPreorder(string s) {
        stack<TreeNode*>st;
        int d=0,i=0,l=s.length();;
        int x=getNumber(s,i);
        TreeNode* root=new TreeNode(x);
        st.push(root);

        while(i<l && !st.empty()){
            while(i<l && s[i]=='-')d++,i++; //get the depth of next coming node
            x=getNumber(s,i); //obtain the value that has to be put into node
            while(st.size()>d)st.pop(); //Pop until you get the node of required depth to attach the current node

            if(!st.top()->left){ //If left child is empty , form a new node as left child else form a new node as right child and push the new node into stack 
                st.top()->left=new TreeNode(x);
                st.push(st.top()->left);
            }
            else {
                st.top()->right=new TreeNode(x);
                st.push(st.top()->right);
            }
            d=0; //reset depth 
        }

        /*
            while(!st.empty()){
                while(s[i]=='-')d++,i++;
                x=getNumber(s,i);
                while(!st.empty() && st.size()>d)st.pop();
                if(!st.empty()){
                    if(!st.top()->left){
                        st.top()->left=new TreeNode(x);
                        st.push(st.top()->left);
                    }
                    else {
                        st.top()->right=new TreeNode(x);
                        st.push(st.top()->right);
                    }
            }
            d=0;
        }*/
        return root;
    }
};