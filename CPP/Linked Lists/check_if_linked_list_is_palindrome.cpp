/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-17
 * @desc Given head of a singly linked list, check if given linked list is palindrome or not
 */

//Time Complexity - O(n), Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* reverse(Node* head, Node* end){
    Node *prev=NULL,*curr=head,*later;
    while(curr!=end){
        later=curr->next;
        curr->next=prev;
        prev=curr;
        curr=later;
    }
    return prev;
}

int countNodes(Node* head){
    int cnt=0;
    while(head){
        cnt++;
        head=head->next;
    }
    return cnt;
}

bool isPalindrome(Node *head){
    Node* sp=head,*fp=head;
    while(fp && fp->next){
        sp=sp->next;
        fp=fp->next->next;
    }
    
    int n=countNodes(head);
    
    Node *trav1=reverse(head,sp), *trav2=sp;
    
    if(n%2==1)trav2=trav2->next;
    
    while(trav1 && trav2){
        if(trav1->data==trav2->data){
            trav1=trav1->next;
            trav2=trav2->next;
        }
        else return false;
    }
    if(trav1||trav2)return false;
    else return true;
}


int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        cout<<isPalindrome(head);
        cout << endl;
    }
    return 0;
}
