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
Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* del(Node* root, int key){
    if(root->data>key){
        root->left=del(root->left,key);
    }
    else if(root->data<key){
        root->right=del(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* tmp=root->right;
            free(root);
            return tmp;
        }
        else if(root->right==NULL){
            Node* tmp=root->left;
            free(root);
            return tmp;
        }
        Node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);
    }
    return root;
}
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    struct Node* root= NULL;
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,6);
    inorder(root);
    cout<<endl;
    Node* rr=del(root,5);
    inorder(rr);
}