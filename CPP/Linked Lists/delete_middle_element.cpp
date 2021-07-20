/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-17
 * @desc Given a singly linked list, delete middle of the linked list.
 *       Note: If there are even nodes, then there would be two middle nodes, we need to delete the second middle element.
 */

//Time Complexity - O(n), Space Complexity - O(1)
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
/**
 * Count the nodes, parse half of the nodes and adjust pointers. This requires 2 traversals
 * Slow and fast pointer approach requires only 1 traversal
*/
Node* deleteMid(Node* head){ 
    if(!head->next){ //If there is only 1 node
        delete head;
        return NULL;
    }

    Node *trav1=head,*trav2=head, *temp; //trav1 moves at 1X speed, while trav2 moves at 2X speed

/*If the no.of nodes are odd - trav2 will be pointing to last node and trav1 will be pointing to middle node
 *If the no.of nodes are even - trav2 will be pointing to last but 1 node and trav1 will be pointing to first middle node
*/
    while(trav2->next && trav2->next->next){
        trav1=trav1->next;
        trav2=trav2->next->next;
    }

    if(!trav2->next){ //Odd case - trav1 points to the middle node that has to be deleted
        trav1->data=trav1->next->data;
        temp=trav1->next;
        trav1->next=trav1->next->next;
        delete temp;
    }
    else { //Even case - trav1 points to the first middle node
        temp=trav1->next;
        trav1->next=trav1->next->next;
        delete temp;
    }
    return head;
}

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 

int main() { 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 

