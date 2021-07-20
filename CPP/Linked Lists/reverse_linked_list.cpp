/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-17
 * @desc Given head of a linked list of N nodes. The task is to reverse this list.
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

struct Node* reverseList(struct Node *head){ //However head would be altered, you can use head instead of temp 

    if(!head||!head->next)return head;
    
    Node *prev=NULL,*curr=head, *temp;
    while(curr){
        temp=curr->next; //Preserve the curr->next, link to next elements
        curr->next=prev; //Point curr->next to previous node
        prev=curr;  //make current node as previous node
        curr=temp;  //assign the preserved link to curr
    }
    return prev;
}
    
void printList(struct Node *head)
{
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
        
        head =reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}
