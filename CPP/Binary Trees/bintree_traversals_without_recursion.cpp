#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pi pair<int,int>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> inOrder(Node* root){ //Altering the statements in the if block fetches you postOrder
   vector<int>v;
   stack<pair<Node*,bool>>s;
   s.push({root,1});
   while(!s.empty()){
	   pair<Node*,bool> p=s.top();
	   s.pop();
	   if(p.second){
		   if(p.first->right)s.push({p.first->right,1}); 
		   s.push({p.first,0});//visiting for the first time, make the boolean value false and push the current node back onto stack
		   if(p.first->left)s.push({p.first->left,1});
		   
	   }
	   else v.push_back(p.first->data);
   }
   return v;
}
vector<int> postOrder(Node* root) {
    vector<int>v;
    Node * temp= root;
    stack<Node* >s1,s2;
    s1.push(root);
    while(!s1.empty()){
        temp=s1.top();
        s1.pop();
        s2.push(temp);  //Stores reverse of post order traversal
        if(temp->left)s1.push(temp->left);
        if(temp->right)s1.push(temp->right); 
    }
    while(!s2.empty()){
        v.push_back(s2.top()->data);
        s2.pop();
    }
    return v;
}
int main(){
    return 0;
}
