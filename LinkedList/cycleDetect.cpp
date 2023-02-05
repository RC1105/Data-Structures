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

bool isCycle (ListNode* head){
    ListNode* hare=head;
    ListNode* torr=head;
    while(hare!=NULL){
        
        hare=hare->next->next;
        torr=torr->next;
        if(hare==torr){
            return true;
        }
        if(hare->next==NULL){
            return false;
        }
        
    }
    return false;
}

int main(){
    ListNode* head=new ListNode(7);
    head->next=new ListNode(11);
    head->next->next=new ListNode(13);
    head->next->next->next=new ListNode(18);
    head->next->next->next->next=new ListNode(27);
    cout<<isCycle(head);
}