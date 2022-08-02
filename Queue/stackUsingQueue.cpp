#include "bits/stdc++.h"
using namespace std;
queue<int> q1,q2;

class MyStack {
    public:
    void push(int x) {
        while(!q2.empty()){
            int k= q2.front();
            q2.pop();
            q1.push(k);
        }
        q2.push(x);
            while(!q1.empty()){
            int k= q1.front();
            q1.pop();
            q2.push(k);
        }
    }

    int pop() {
        int k=q2.front();
        q2.pop();
        return k;
    }

    int top() {
        return q2.front();
    }

    bool empty() {
        return q2.empty();
    }
};
int main(){
    MyStack* obj = new MyStack();
    obj->push(4);
    obj->push(7);
    obj->push(8);
    cout<<obj->top()<<endl;
    cout<<obj->empty()<<endl;
    cout<<obj->pop()<<endl;
    
    cout<<obj->empty()<<endl;   
    cout<<obj->pop()<<endl;
    cout<<obj->pop()<<endl;
    cout<<obj->empty()<<endl;   
    
}