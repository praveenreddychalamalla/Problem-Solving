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
Node* mergeTwoLists(Node* head1, Node* head2) {
   if(!head1)return head2;
   if(!head2)return head1;
   
   Node *head = new Node(-1), *tail=head; //Dummy Node

   while(head1 && head2){
       if(head1->data<head2->data){
           tail->next=head1;
           head1=head1->next;
       }
       else {
           tail->next=head2;
           head2=head2->next;
       }
       tail=tail->next;
   }
   if(head1)tail->next=head1;
   if(head2)tail->next=head2;
   return head->next;
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
