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

bool isBST(Node* root, Node* min, Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<= min->data){
        cout<<root->data;
        return false;
    }
    if(max!=NULL && root->data>= max->data){
        return false;
    }
    
    bool l=isBST(root->left,min,root);
    bool r=isBST(root->right,root,max);
    return r && l;
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
    struct Node* root=NULL;
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,6);
    inorder(root);
    cout<<endl;
    cout<<isBST(root,NULL,NULL);
   return 0;
}
