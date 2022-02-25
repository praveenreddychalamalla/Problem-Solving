/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-09-09
 * @desc Sort the linked list in ascending order
 */

//Time Complexity - O(n * log n), Space Complexity - O(n)


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

 void merge(Node* left, Node* mid, Node* right){ //Same as merge funtion in merge sort
    Node *head=new Node(-1), *tail=head; //Create Dummy Node
    Node *trav1=left, *trav2= mid->next;

    while(trav1!=mid->next && trav2!=right->next){
        if(trav1->data<trav2->data){
            tail->next=new Node(trav1->data);
            trav1=trav1->next;
        }
        else{
            tail->next=new Node(trav2->data);
            trav2=trav2->next;
        }
        tail=tail->next;
    }

    while(trav1!=mid->next){
        tail->next=new Node(trav1->data);
        trav1=trav1->next;
        tail=tail->next;
    }

    while(trav2!=right->next){
        tail->next=new Node(trav2->data);
        trav2=trav2->next;
        tail=tail->next;
    }

    trav1=head->next; //skip dummy node
    trav2=left;
    while(trav1){
        trav2->data=trav1->data;
        trav2=trav2->next;
        trav1=trav1->next;
    }
    free(head); //Free temporary linked list
    return ;
}
void MergeSort(Node* left, Node* right){
    if(left!=right){
        Node *sp=left,*fp=left;
        while(fp!=right && fp->next!=right){ //O(n) time
            sp=sp->next;
            fp=fp->next->next;
        }
        Node *mid=sp;
        MergeSort(left,mid);
        MergeSort(mid->next,right);
        merge(left,mid,right); // O(n) time
    }
}

Node* mergeSort(Node* head) {
    Node* left=head, *right=head;
    while(right->next)right=right->next; //Pass  left end and right end of linked list to recursive function
    MergeSort(left,right);
    return head;
    
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
} 
