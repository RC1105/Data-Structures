#include "bits/stdc++.h"
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode (int val){
        data=val;
        next=NULL;
    }
};

void traverse (ListNode* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

ListNode* reverseK(ListNode* &head, int k){
    if(head==NULL){
        return NULL;
    }
    int pos=0;
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* nexx=curr->next;
    while(curr!=NULL && pos<k){
        pos++;
        nexx=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nexx;
    }
    ListNode* tmp=prev;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=nexx;
    //cout<<nexx->data;
    //tmp->next=nexx;
    return prev;
}
int main(){
    ListNode* head=new ListNode(7);
    head->next=new ListNode(11);
    head->next->next=new ListNode(13);
    
    head->next->next->next=new ListNode(18);
    traverse(head);
    ListNode* head2=reverseK(head,2);
    cout<<endl;
    traverse(head2);
    
}