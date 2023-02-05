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
ListNode* insertAtHead(ListNode* &head, int val){
    ListNode* tmm=new ListNode(val);
    tmm->next=head;
    head=tmm;
    return head;
}

ListNode* insertAtTail(ListNode* &head, int val){
    ListNode* tmm=new ListNode(val);
    ListNode* tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=tmm;
    return head;
}
ListNode* insertAtPos(ListNode* &head, int val, int pos){
    if(pos==0){
        return insertAtHead(head,val);
    }
    else{
        int k=1;
        ListNode* tmp=head;
        ListNode* tmm=new ListNode(val);
        while(k!=pos && head->next!=NULL){
            tmp=tmp->next;
            k++;
        }   
        ListNode* tmk=tmp->next;
        tmp->next=tmm;
        tmm->next=tmk;
        return head;
    }
}
int main(){
    ListNode* head=new ListNode(7);
    head->next=new ListNode(11);
    head->next->next=new ListNode(13);
    traverse(head);
    cout<<endl;
    //ListNode* head2=insertAtHead(head,3);
    //ListNode* head2=insertAtTail(head,18);
    ListNode* head2=insertAtPos(head,18,1);
    traverse(head2);
}