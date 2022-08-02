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

int search(int inorder [], int curr, int start, int end){
    for(int i=start; i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* constTree(int preorder[], int inorder[], int start, int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    Node* node=new Node(curr);
    if(start==end){
        return node;
    }
    int pos=search(inorder, curr, start, end);
    node->left=constTree(preorder,inorder, start, pos-1);
    node->right=constTree(preorder,inorder, pos+1, end);
    return node;
    
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
    int inorder[]={4,2,1,5,3};
    Node* boot=constTree(preorder,inorder,0,4);
    order(boot);
    return 0;
}
