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
int insersect(ListNode* head, ListNode* head2){
    while(head!=NULL || head2!=NULL){
        if(head==head2){
            return head->data;
        }
        head=head->next;
        head2=head2->next;
    }
    return -1;
}
int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    
    ListNode* head2=new ListNode(7);
    head2->next=new ListNode(11);
    head2->next->next=new ListNode(13);
    head2->next->next->next=new ListNode(18);
    head2->next->next->next->next=new ListNode(16);
    head->next->next=head2->next->next->next;
    traverse(head);
    cout<<endl;
    traverse(head2);
    cout<<endl;
    
    int l1=lenn(head);
    int l2=lenn(head2);
    if(l1<l2){
        int pos=l2-l1;
        while(pos!=0){
            pos=l2-l1;
            head2=head2->next;
            pos--;
        }
    }
    else{
        int pos=l1-l2;
        while(pos!=0){
            pos=l1-l2;
            head=head->next;
            pos--;
        }
    }
    int lx=lenn(head);
    int ly=lenn(head2);
    //cout<<lx<<" "<<ly;
    cout<<insersect(head,head2);
}