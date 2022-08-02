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

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return (max(height(root->left),height(root->right))+1);
}
bool isBalanced(Node* root){
    if(root==NULL){
        return false;
    }
    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }
    int left=height(root->left);
    int right=height(root->right);
    if(abs(left-right)<=1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    struct Node* root= NULL;
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,9);
    root=insert(root,10);
    root=insert(root,11);
    cout<<isBalanced(root)<<endl;
    return 0;
}
