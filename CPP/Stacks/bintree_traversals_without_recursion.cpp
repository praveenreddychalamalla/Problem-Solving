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

vector<int> inOrder(Node* root){
    vector<int>v;
    Node* temp=root;
    stack<Node*>s;
    s.push(root);
    temp=temp->left;
    while(!s.empty()||temp){
        if(temp){
            s.push(temp);
            temp=temp->left;
        }
        else{
            v.push_back(s.top()->data);
            temp=s.top();
            s.pop();
            temp=temp->right;
        }
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
