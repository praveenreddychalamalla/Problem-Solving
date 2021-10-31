/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-10-23
 * @desc Given K sorted linked lists of different sizes. 
 *       The task is to merge them in such a way that after merging they will be a single sorted linked list.
 */

//Time Complexity - O(n*k log k), Space Complexity - O(k)
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

class Compare{
    public:
    bool operator() (Node *a, Node *b){
        return a->data>b->data;
    }
};
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *a[], int K)
    {
           priority_queue<Node*,vector<Node*>,Compare> pq;
           for(int i=0;i<K;i++){
               if(a[i])pq.push(a[i]);
           }
           Node *head=new Node(-1),*trav=head;
           while(!pq.empty()){
               Node *temp=pq.top();
               pq.pop();
               trav->next=new Node(temp->data);
               if(temp->next){
                   pq.push(temp->next);
               }
               trav=trav->next;
           }
           return head->next;
    }
};

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }
	return 0;
}