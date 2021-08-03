/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-02
 * @desc Clone a linked list with random pointers
 */
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
