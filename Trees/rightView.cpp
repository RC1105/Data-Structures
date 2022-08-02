
#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    else if(root->data > val){
        root->left=insert(root->left,val);
    }
    else{ 
        root->right=insert(root->right,val);
    }
    return root;
}


void RV(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0; i<n;i++){    
            Node* curr=q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
int main(){
    struct Node* root= NULL;
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,9);
    root=insert(root,10);
    root=insert(root,11);
    
    RV(root);
    return 0;
}
