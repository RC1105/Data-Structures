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

ListNode* mergeSorted(ListNode* head1, ListNode* head2){
    if(head1==NULL){
        return head2;
    }
    else if (head2==NULL){
        return head1;
    }
    ListNode* answer=new ListNode(0);
    ListNode* ans=answer;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            ans->next=new ListNode(head1->data);
            ans=ans->next;
            head1=head1->next;
        }
        else if(head2->data<head1->data){
            ans->next=new ListNode(head2->data);
            ans=ans->next;
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        
            ans->next=new ListNode(head1->data);
        ans=ans->next;
        head1=head1->next;
    }
    while(head2!=NULL){           
        ans->next=new ListNode(head2->data);
        ans=ans->next;
        head2=head2->next;
    }
    
    ans->next=NULL;
    return answer->next;
}
int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next= new ListNode(6);
    
    ListNode* head2=new ListNode(7);
    head2->next=new ListNode(11);
    head2->next->next=new ListNode(13);
    head2->next->next->next=new ListNode(18);
    head2->next->next->next->next=new ListNode(16);
    traverse(head);
    cout<<endl;
    traverse(head2);
    cout<<endl;
    ListNode* head3=mergeSorted(head,head2);
    traverse(head3);
}