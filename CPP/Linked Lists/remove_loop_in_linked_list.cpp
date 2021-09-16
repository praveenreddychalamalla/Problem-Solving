/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-07-21
 * @desc Given a linked list of N nodes. Remove the loop in linked list if present
 */

//Time Complexity - O(n), Space Complexity - O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};
void removeLoop(Node* head){
    
    Node*fp=head,*sp=head;
    while(fp && fp->next){
        sp=sp->next;
        fp=fp->next->next;
        if(sp==fp){
            sp=head;
            if(fp==sp){ //If sp and fp meet at start of loop, only increment one of the pointers
                while(fp->next!=sp)fp=fp->next;
            }
            else{
                while(fp->next!=sp->next){
                    sp=sp->next;
                    fp=fp->next;
                }
            }
            fp->next=NULL;
            return;
        }
    }
    return ;
}

bool detectLoop(Node* head){

    Node *sp=head,*fp=head;
    while(fp && fp->next){
        sp=sp->next;
        fp=fp->next->next;
        if(sp==fp)return true;
    }
    return false;
}

int length(Node* head){
    int cnt=0;
    while(head){
        cnt++;
        head=head->next;
    }
    return cnt;
}

void loopHere(Node* head, Node* tail, int position){

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
        
        removeLoop(head);
        
        if( detectLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}