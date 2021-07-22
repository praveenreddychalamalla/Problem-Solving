/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-21
 * @desc Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.
 */

//Time Complexity - O(n), Space Complexity - O(1).
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
/**
 * Floyd's Loop Detection Algorithm - Slow and Fast Pointer Technique.
 * If Slow Pointer is incremented by 1 at a time and Fast Pointer incremented by 2 at a time, both will meet at some node in the loop. (Happens before slow pointer visits all nodes)
 * The pointing of meet depends on 2 factors - No.of nodes in the loop and the position where the fast pointer lands in the loop for the first time
 * 
 * Note : If the no.of nodes in the loop is even - Fast Pointer will not visit all the nodes.
 *        If the no.of nodes in the loop is odd - Fast Pointer will visit all the nodes.
 * 
 * Another Key Observation: Helpful if you have to remove the loop in Linked List. This can be solved, if you can stand at last node in the loop.
 * Floyd's Loop Detection Algorithm leaves you with the node where slow and fast pointer meets. 
 * At this instance, if you initialize one of the pointers to head of the Linked List (say sp=head) and increment both the pointers at same pace, they will meet at starting of the loop ):-
 * You can modify this a bit i.e., while(sp->next!=fp->next) increment both pointers by 1. This will leave you in the desired position
 * 
*/
bool detectLoop(Node* head){

    Node *sp=head,*fp=head;
    while(fp && fp->next){
        sp=sp->next;
        fp=fp->next->next;
        if(sp==fp)return true;
    }
    return false;
}

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        if(detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}