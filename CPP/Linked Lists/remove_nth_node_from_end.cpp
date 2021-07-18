/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-18
 * @desc Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 */
//Time Complexity - O(n), Space Complexity - O(1)
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
/*Can also delete (n-k+1)th  node from front, but requires 2 traversals (one for counting nodes and other for operation)
 *
 *In order to delete k th node from end, you have to stand at k+1 th node from end (n-k th node from front) to adjust pointers.
 *Separate two pointers by distance k, then increment both pointers until one of it points to NULL. 
 *Now t1 points to just after last node and as the distance between them is k, t2 will be effectively pointing to (n-k)th node from front which is the desired position
*/
 Node* removeNthFromEnd(Node* head, int k) { 

    Node *t1,*t2,*x; 
    t1=head;t2=NULL;
    int d=k;
    while(d--)t1=t1->next; //Increment t1 until you pass k nodes, so that the two pointers can be separated by distance k
    while(t1){ //Increment both pointers util t1 is NULL
        if(!t2)t2=head;
        else t2=t2->next;
        t1=t1->next;
    }
    if(!t2){ //If t2 is still NULL, then it must be the case that you have to delete last node from the end, which is the first node from front
        x=head;
        head=head->next;
    }
    else{
        x=t2->next;
        t2->next=t2->next->next;
    }
    delete x;
    return head;
    
    
}

int main()
{
    int T,i,n,k,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>k>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        removeNthFromEnd(head,k);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}