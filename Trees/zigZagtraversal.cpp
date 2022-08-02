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


void zigZag(Node* root){
    stack<Node*> currLevel;
    stack<Node*> nexxLevel;
    bool leftToRight=true;
    currLevel.push(root);
    while(!currLevel.empty()){
        Node* temp=currLevel.top();
        currLevel.pop();
        if(temp!=NULL)
            cout<<temp->data;
        if(leftToRight){
            if(temp->left){
                nexxLevel.push(temp->left);
            }
            if(temp->right){
                nexxLevel.push(temp->right);
            }
        }
        if(!leftToRight){
            if(temp->right){
                nexxLevel.push(temp->right);
            }
            if(temp->left){
                nexxLevel.push(temp->left);
            }
        }
        if(currLevel.empty()){
            swap(currLevel,nexxLevel);
            leftToRight=!leftToRight;
        }
    }
    
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
    zigZag(root);
   
}