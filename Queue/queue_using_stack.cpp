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
        if (s1.empty() && s2.empty()){
            //cout<<"Queue is empty";
            return -1;
        }
        else if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val=s2.top();
        s2.pop();
        return val;
    }
    bool isempty( ){
        if(s1.empty() && s2.empty()){
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
    cout<<endl;
    cout<<q1.pop();
    cout<<endl;
    cout<<q1.pop();
    cout<<endl;
    cout<<q1.pop();
    return 0;
}
