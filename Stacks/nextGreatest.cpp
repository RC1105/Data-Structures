#include "bits/stdc++.h"
using namespace std;


void nexxGreater(vector<int> ques){
    int n=ques.size();
    vector<int> ans(n,0);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        int curr=ques[i];
        if(!st.empty() && curr< st.top()){
            ans[i]=st.top();
            st.push(curr);
        }
        else if(st.empty()){
            ans[i]=-1;
            st.push(curr);
        }
        else{
            while(!st.empty()){
                if(curr<st.top()){
                    ans[i]=st.top();
                    st.push(curr);
                    break;
                }
                st.pop();
                if(st.empty()){
                    ans[i]=-1;
                    st.push(curr);
                    break;
                }
            }
            
        }
    }
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    vector<int> ques={4,12,5,3,1,2,5,3,1,2,4,6};
    nexxGreater(ques);
    return 0;
}
