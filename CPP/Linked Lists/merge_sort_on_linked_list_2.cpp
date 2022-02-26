/**
 * @author Praveen Reddy Chalamalla
 * @create date 2022-02-25
 * @desc sort the given linked list in ascending order 
 */

//Time Complexity - O(n * log n), Space Complexity - O(log n) {For recursion}


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* getMid(ListNode* head){
        ListNode* sp=head,*fp=head;
        while(fp->next && fp->next->next){
            sp=sp->next;
            fp=fp->next->next;
        }
        ListNode* mid=sp->next;
        sp->next=NULL; //Break the list
        return mid;
    }
    ListNode* merge(ListNode* head1, ListNode*head2){
        ListNode* head=new ListNode(),*tail=head;
        while(head1 && head2){
            if(head1->val<head2->val)tail->next=head1,head1=head1->next;
            else tail->next=head2,head2=head2->next;
            tail=tail->next;
        }
        if(head1)tail->next=head1;
        if(head2)tail->next=head2;
        return head->next;
    }
    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next)return head;
        ListNode *mid=getMid(head);
        ListNode* left=mergeSort(head);
        ListNode* right=mergeSort(mid);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);;
    }
};