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


Node* constBST(int preorder[], int* preorderIdx, int key, int min, int max, int n){
    if(*preorderIdx>=n){
        return NULL;
    }
    Node* root=NULL;
    if(key>min && key<max){
        root=new Node(key);
        *preorderIdx=*preorderIdx+1;
        if(*preorderIdx<n){
            root->left=constBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n){
            root->right=constBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;
    
}

void order(struct Node* root){
    if(root==NULL){
        return;
    }
    order(root->left);
    cout<<root->data<<" ";
    order(root->right);
}

int main(){
    int preorder[]={1,2,4,3,5};
    int preorderIdx=0;
    int n=5;
    Node* boot=constBST(preorder,&preorderIdx,preorder[0],INT_MIN, INT_MAX, n);
    order(boot);
}