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

ListNode* reverse(ListNode* &head){
    if(head==NULL){
        return NULL;
    }
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* nexx=curr->next;
    while(curr!=NULL){
        nexx=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nexx;
    }
    return prev;
}
int main(){
    ListNode* head=new ListNode(7);
    head->next=new ListNode(11);
    head->next->next=new ListNode(13);
    traverse(head);
    ListNode* head2=reverse(head);
    cout<<endl;
    traverse(head2);
    
}