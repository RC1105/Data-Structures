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
int main(){
    ListNode* head=new ListNode(7);
    head->next=new ListNode(11);
    head->next->next=new ListNode(13);
    traverse(head);
}