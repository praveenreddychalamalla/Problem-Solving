/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-11
 * @desc Convert a sorted array to a Height Balanced BST and find it's preorder
 */

//Time Complexity - O(n), Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node{
        int data;
        struct Node* left;
        struct Node* right;
        Node(int x){
            data=x;
            left=NULL;
            right=NULL;
        }
    };
    Node* buildTree(int l, int r,vector<int>& a){
        if(l<=r){
            int m=(l+r)/2;
            Node *root=new Node(a[m]);
            root->left=buildTree(l,m-1,a);
            root->right=buildTree(m+1,r,a);
        }
        else return NULL;
    }
    vector<int>res;
    void preOrder(Node* root){
        if(root){
            res.push_back(root->data);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    
    vector<int> sortedArrayToBST(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        Node* root=buildTree(l,r,nums);
        res.clear();
        preOrder(root);
        return res;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
} 