/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-20
 * @desc Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
 */

//Time Complexity - O(n), Space Complexity - O(1)
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node* mergeTwoLists(Node* l1, Node* l2) {
        
    if(!l1) return l2;
    if(!l2)return l1;
    
    Node *head=NULL,*trav1=l1,*trav2=l2,*curr; //Curr points to end node of merged list so far
    
    head=l1->data<=l2->data?l1:l2;
    curr=head;

    if(curr==l1)trav1=trav1->next;
    else trav2=trav2->next;

    while(trav1&&trav2){
        if(trav1->data<=trav2->data){
            curr->next=trav1;
            trav1=trav1->next;
        }
        else{
            curr->next=trav2;
            trav2=trav2->next;
        }
        curr=curr->next;
    }
    if(trav1)curr->next=trav1;
    if(trav2)curr->next=trav2;
    return head;
}

void printList(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head1 = NULL,*head2=NULL, *tail = NULL,*head=NULL;

        cin>>n;
        
        cin>>firstdata;
        head1 = new Node(firstdata);
        tail = head1;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        cin>>n;
        
        cin>>firstdata;
        head2 = new Node(firstdata);
        tail = head2;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        head=mergeTwoLists(head1,head2);
        printList(head);
        cout << endl;
    }
    return 0;
}
