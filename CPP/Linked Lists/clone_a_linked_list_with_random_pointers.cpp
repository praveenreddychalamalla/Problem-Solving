/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-02
 * @desc Clone a linked list with random pointers
 */

//Time Complexity - O(n), Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head){
  Node* trav1=head;
  while(trav1){   //Alter next pointers of original list and connect newly formed nodes with original list
	  Node *temp=new Node(trav1->data);
	  temp->next=trav1->next;
	  trav1->next=temp;
	  trav1=temp->next;
  }
  trav1=head;
  while(trav1){ //Adjust the random pointers
	  if(trav1->arb)trav1->next->arb=trav1->arb->next;
	  trav1=trav1->next->next;
  }
  Node* cloneHead=head->next, *trav2=cloneHead;
  trav1=head;
  while(trav1 && trav2){ //adjust next pointers of cloned list and original list
	  trav1->next=trav1->next->next;
	  if(trav2->next)trav2->next=trav2->next->next;
	  trav1=trav1->next;
	  trav2=trav2->next;
  }
  return cloneHead;
}
/** Time Complexity - O(n) , Space Complexity - O(n)
 * 
    Node *copyList(Node *head){

        unordered_map<Node*, Node*>m;
        Node *trav1=head,*trav2=NULL;
        while(trav1){
            trav2= new Node(trav1->data);
            m[trav1]=trav2;
            trav1=trav1->next;
        }
        trav1=head;
        while(trav1){
            trav2=m[trav1];
            trav2->next=m[trav1->next];
            trav2->arb=m[trav1->arb];
            trav1=trav1->next;
        }
        return m[head];
    }
*/
int main()
{
    Node* head=new Node(10);
    head->next=new Node(1);
    head->next->next=new Node(2);
    head->next->next->next=new Node(3);
    head->next->next->next->next=new Node(4);
    head->arb=head->next->next; //connecting 10,2
    head->next->next->next->next->arb=head->next ; //connecting 4,1
    Node* cloneHead=copyList(head);
}