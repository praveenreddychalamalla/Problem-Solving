/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-09
 * @desc Reverse the linked list in groups of K. If group size at end is less than k, consider them as 1 group and reverse them 
 */

//Time Complexity - O(n), Space Complexity - O(1)


#include <bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

node* reverseK(node* trav1, node *trav2){ //Reverse the nodes int between [trav1 && trav2)

    node* prev=NULL, *curr=trav1,*later;
    while(curr!=trav2){
        later=curr->next;
        curr->next=prev;
        prev=curr;
        curr=later;
    }
    return prev; //return head of reversed list
}
struct node *reverse (struct node *head, int k){ 

    int cnt=0;
    node* trav1=head,*trav2=head, *prev=trav1,*later; 

    while(cnt<k && trav2){
        cnt++;
        trav2=trav2->next;
    }
    later=trav2; //Link to the further list will be lost while reversing, hence preserve this.
    head=reverseK(trav1,trav2); //Reverse first group and store the head
    trav2=later; //Set the stored link

    while(trav2){
        trav1=trav2;
        cnt=0;
        while(cnt<k && trav2){
            cnt++;
            trav2=trav2->next;
        }
        later=trav2;
        prev->next=reverseK(trav1,trav2); //Prev points to end node (after reversal) in the previous group. Connect previous group and current group 
        trav2=later;
        prev=trav1; //Assign current group end node to prev. After reversal trav1 becomes end and trav2 becomes start
    }
    return head;
}


void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        head = reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends