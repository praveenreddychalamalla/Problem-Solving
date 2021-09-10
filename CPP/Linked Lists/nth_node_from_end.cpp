/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-09
 * @desc Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.
 */

//Time Complexity - O(n), Space Complexity - O(1)
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;


struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int getNthFromLast(Node *head, int n){ //Can be accomplished in one traversal

    Node *sp=head, *fp=head; //Separate the two pointers by a distance of n
    while(fp && n){
        n--;
        fp=fp->next;
    }
    if(!fp && n!=0)return -1;
    while(fp){
        sp=sp->next;
        fp=fp->next;
    }
    return sp->data;
       
}
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}