/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-05
 * @desc Add two numbers represented by linked lists
 */

//Time Complexity - O(m+n), Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverse(Node* head){
    Node*prev=NULL,*curr=head,*later;
    while(curr){
        later=curr->next;
        curr->next=prev;
        prev=curr;
        curr=later;
    }
    return prev;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    first=reverse(first);
    second=reverse(second);
    Node* head=new Node(0),*curr=head;
    int s=0,c=0;
    while(first&&second){
        s=first->data+second->data+c;
        curr->next=new Node(s%10);
        c=s/10;
        curr=curr->next;
        first=first->next;
        second=second->next;
    }
    while(first){
        s=first->data+c;
        curr->next=new Node(s%10);
        c=s/10;
        curr=curr->next;
        first=first->next;
    }
    while(second){
        s=second->data+c;
        curr->next=new Node(s%10);
        c=s/10;
        curr=curr->next;
        second=second->next;
    }
    if(c==1)curr->next=new Node(c);
    head=reverse(head->next);
    return head;
}

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
