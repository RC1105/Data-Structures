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

int no(Node* root){
    if(root==NULL){
        return 0;
    }
    return (1+no(root->left)+no(root->right));    
}

int main(){
    struct Node* root= NULL;
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,9);
    root=insert(root,10);
    root=insert(root,11);
    cout<<no(root)<<endl;
    return 0;
}
