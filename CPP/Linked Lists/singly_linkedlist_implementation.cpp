/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-17
 * @desc Implementation of singly Linked List
 * N operations - Operation format :   AF value
 *                                     AL value
 *                                     RF
 *                                     SR
 * 
 */
#include<bits/stdc++.h>
using namespace std;
struct Node{
  int val;
  Node* next;
  Node(int x){
    val=x;
    next=NULL;
  }
};
void printSLL(Node* head){
  Node *temp=head;
  while(temp){
    cout<<temp->val<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
Node* addFirst(Node* head,int x){
    Node* newNode=new Node(x);
    if(!head)
        return newNode;
    newNode->next=head;
    return newNode;
}
Node* addLast(Node* head,int x){
    Node* newNode=new Node(x);
    if(!head)
        return newNode;
    Node* temp=head;
    while(temp->next)  temp=temp->next;
    temp->next=newNode;
    return head;
}
Node* removeFirst(Node* head){
    Node* temp=head;
    head=head->next;
    free(temp);
    return head; 
}
Node* shiftRight(Node* head){
    if(!head->next)return head;
    Node* temp=head;
    while(temp->next->next) temp=temp->next;
    temp->next->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;
}
void solve(){
  int n,x;
  string s;
  cin>>n;
  map<string,int>m;
  m["AF"]=1;m["AL"]=2;m["RF"]=3;m["SR"]=4;
  Node *head=NULL;
  while(n--){
    cin>>s;
    switch(m[s]){
      case 1: cin>>x;
              head=addFirst(head,x);
              printSLL(head);
              break;

      case 2: cin>>x;
              head=addLast(head,x);
              printSLL(head);
              break;

      case 3: if(!head)cout<<"null"<<endl;
              else{
                cout<<head->val<<endl;
                head=removeFirst(head);
                if(!head)cout<<"EmptyList"<<endl;
                else printSLL(head);
              }
              break;
      case 4: if(!head)cout<<"EmptyList"<<endl;
              else{
                head=shiftRight(head);
                printSLL(head);
              }
              break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
    solve();

  return 0;
}
