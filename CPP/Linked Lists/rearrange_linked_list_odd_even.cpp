/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-17
 * @desc Rearrange the linked list in a way that all odd position nodes are together and all even positions node are together.
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

void rearrangeEvenOdd1(Node *head)// Method 1 - O(2*n)
{
    if(!head||!head->next||!head->next->next) return;
    int cnt=0;
    Node *temp=head;
    Node *tail=head;
    while(tail->next){
        tail=tail->next;
        cnt++;
    }
    cnt++;// Last node is not counted in the loop
    cnt/=2; //No of operations
    while(cnt--){ 
        tail->next=temp->next; //Attach the even node at the end
        temp->next=temp->next->next; //Make the curr odd node to point to next odd node
        tail=tail->next; //Increment tail 
        tail->next=NULL; //Make tail's next as null, because it is the end node now
        temp=temp->next; //Increment temp
    }
    return ;
}

void rearrangeEvenOdd1(Node *head) //Method 2- O(n)
{
    if(!head||!head->next||!head->next->next) return;
    Node* oddHead=head;
    Node* evenHead=head->next;
    Node* oddPtr=oddHead;
    Node* evenPtr=evenHead;
    while(evenPtr && evenPtr->next){
        oddPtr->next=oddPtr->next->next;
        evenPtr->next=evenPtr->next->next;
        oddPtr=oddPtr->next;
        evenPtr=evenPtr->next;
    }
    oddPtr->next=evenHead; //Attach even list at the end of odd list
    return ;
}

int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
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
        rearrangeEvenOdd1(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}