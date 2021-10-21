/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-10-21
 * @desc You are given an array of n linked-lists lists, each linked-list (each list size<=k )is sorted in ascending order.
 *       Merge all the linked-lists into one sorted linked-list and return it.
 */

//Time Complexity - O(n*k log n), Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge2Lists(ListNode* l1, ListNode* l2){
    ListNode *head=new ListNode(),*temp=head;
    while(l1 && l2){
        if(l1->val<=l2->val){
            temp->next=l1;
            l1=l1->next;
        }
        else{
            temp->next=l2;
            l2=l2->next;
        }
        temp=temp->next;
    }
    if(l1)temp->next=l1;
    if(l2)temp->next=l2;
    return head->next;
}

ListNode* mergeKLists(vector<ListNode*>& a) {
    int n=a.size();
    if(n==0)return NULL;
    while(n>1){
        int i=0,j=n-1;
        while(i<j){
            a[i]=merge2Lists(a[i],a[j]);
            a.pop_back();
            i++;
            j--;
        }
        n=(n-1)/2+1;
    }
    return a[0];
}