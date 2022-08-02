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
bool search(struct Node* root, int val){
    if(root==NULL){
        return false;
    }
    if(root->data==val){
        return true;
    }
    else if(root->data>val){
        search(root->left,val);
    }
    else{
        search(root->right,val);
    }
    return false;
}
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

void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    
    inorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    struct Node* root= NULL;
    root=insert(root,7);
    root=insert(root,8);
    inorder(root);
    cout<<search(root,9);
}