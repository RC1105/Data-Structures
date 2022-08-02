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
Node* LCA(Node* root, int n1, int n2){
    if(root==NULL){
        return root;
    }
    if (root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLCA= LCA(root->left,n1,n2);
    Node* rightLCA=LCA(root->right,n1,n2);
    if(leftLCA && rightLCA){
        return root;
    }
    else if(leftLCA!=NULL){
        return LCA(root->left,n1,n2);;
    }
    return LCA(root->right,n1,n2);;
}
int dist(Node* lca, int k, int dis){
    if(lca==NULL){
        return -1;
    }
    if(lca->data==k){
        return dis;
    }
    int left=dist(lca->left, k, dis+1);
    if(left!=-1){
        return left;
    }
    return dist(lca->left, k, dis+1);

}

int distance( Node* root, int n1, int n2){
    Node* lca=LCA(root,n1,n2);
    int d1=dist(lca,n1,0);
    int d2=dist(lca,n2,0);
    return d1+d2;
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
    int n1=4;
    int n2=2;
    cout<<distance(root,n1,n2);
    
}
