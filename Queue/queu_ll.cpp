#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node (int val){
        data=val;
        next=NULL;
    }
};
class queue{
    int *arr;
    node *front;
    node *back;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* n=new node(x);
        if (front==NULL){
            
            back=n;
            front=n;
        }

        back->next=n;
        back=n;
    }
    void pop(){
        if (front==NULL){
            cout<<"Nothing left to pop";
            return;
        }
        node *todelete=front;
        front=front->next;
        delete todelete;
    }
    int peek(){
        if (front==NULL){
            cout<<"Nothing left to pop";
            return -1;
            
        }
        else{
            return front->data;
        }
        
    }

};
int main(){
    queue q1;
    q1.push(7);
    q1.push(8);
    cout<<q1.peek()<<endl;
    q1.pop();
    cout<<q1.peek()<<endl;
    q1.pop();
    cout<<q1.peek()<<endl;
    return 0;
}
