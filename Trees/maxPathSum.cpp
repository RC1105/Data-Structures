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
int maxPathSum(Node* root, int &ans){
    if(root==NULL){
        return 0;
    }
    int left=maxPathSum(root->left,ans);
    int right=maxPathSum(root->left,ans);
    int nodeMax= max(max(root->data, root->data +left+ right),max(root->data+ left , root->data+right));
    ans=max(ans, nodeMax);
    int answer=max(root->data, max(root->data+left, root->data +right));
    return answer;
}
int maxPathSumAns(Node* root){
    int ans=INT_MIN;
    maxPathSum(root,ans);
    return ans;
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
    
    cout<<maxPathSumAns(root);
    
}