
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


void Lot(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
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
    Lot(root);
    return 0;
}
