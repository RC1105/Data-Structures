#include "bits/stdc++.h"
using namespace std;
class que{
    stack <int> s1;
    stack <int> s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if (s1.empty()){
            cout<<"empty";
            return -1;
        }
        int x=s1.top();
        s1.pop();
        if (s1.empty()){
            return x;
        }
        int item=pop();
        s1.push(x);
        return item;        
        
    }
    bool isempty( ){
        if(s1.empty()){
             return true;
        }
        return false;
    }
};
int main(){
    que q1;
    q1.push(1);
    q1.push(2);
    
    q1.push(3);
    cout<<q1.pop();
    cout<<q1.pop();
    cout<<q1.pop();
    cout<<q1.pop();
    
}