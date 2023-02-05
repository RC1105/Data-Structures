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

ListNode* deleteHead(ListNode* head){
    if(head==NULL){
        return NULL;
    }
    return head=head->next;
}
ListNode* deleteEnd(ListNode* head){
    if(head==NULL){
        return NULL;
    }
    else{
        ListNode* prev=NULL;
        ListNode* tmp=head;
        while(tmp->next!=NULL){
            prev=tmp;
            tmp=tmp->next;
        }
        prev->next=NULL;
    }
    return head;
}
ListNode* deletePos(ListNode* head, int pos){
    if(head==NULL){
        return NULL ;
    }
    else if(pos==0){
        return deleteHead(head);
    }
    else{
        int k=0;
        ListNode* tmp=head;
        ListNode* prev=NULL;
        while(k!=pos && tmp->next!=NULL){
            prev=tmp;
            tmp=tmp->next;
            k++;
        }
        //cout<<tmp->data;
        prev->next=prev->next->next;

    }
    return head;
}
int main(){
    ListNode* head=new ListNode(7);
    head->next=new ListNode(11);
    head->next->next=new ListNode(13);
    traverse(head);
    cout<<endl;
    ListNode* head2=deletePos(head,2);
    traverse(head2);
}