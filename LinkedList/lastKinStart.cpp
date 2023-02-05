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
int lenn(ListNode* head){
    if(head==NULL){
        return 0;
    }
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
}
ListNode* lkis(ListNode* head, int l, int k){
    if(k==0){
        //try reverse;
        return NULL;
    }
    if(head==NULL){
        return NULL;
    }
    int m=l-k;
    int pos=0;
    ListNode* tmm=head;
    ListNode* prevv=head;
    ListNode* prev=prevv;
    while(tmm!=NULL && pos!=m){
        pos++;
        prev=tmm;
        tmm=tmm->next;
    }
    prev->next=NULL;
    ListNode* newHead=tmm;
    ListNode* tmp=newHead;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=prevv;
    return newHead;
}
int main(){
    
    ListNode* head=new ListNode(7);
    head->next=new ListNode(11);
    head->next->next=new ListNode(13);
    traverse(head);
    cout<<endl;
    //cout<<lenn(head);
    ListNode* head2=lkis(head, lenn(head),1);
    cout<<endl;
    traverse(head2);
}