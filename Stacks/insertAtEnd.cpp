#include "bits/stdc++.h"
using namespace std;


void insertEnd(stack<int> &st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int curr=st.top();
    st.pop();
    insertEnd(st,val);
    st.push(curr);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    insertEnd(st,7);
    cout<<st.size();
}