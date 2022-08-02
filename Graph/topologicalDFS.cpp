#include "bits/stdc++.h"
using namespace std;
void topSort(int i, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &s){
    vis[i]=true;
    for(auto itr: adj[i]){
        if(!vis[itr]){
            topSort(itr,adj,vis,s);
        }
    }
    s.push(i);
}
int main(){
    int n,m;
    cout<<"No. of vertices:"; //vertices
    cin>>n;
    cout<<endl<<"No. of nodes:"; //nodes
    cin>>m;
    vector<vector<int>> adjList(n);
    for(int i=0; i<m;i++){
        int x,y;
        cin>>x;
        cin>>y;
        adjList[x].push_back(y);
    }
    vector<bool> visited(n,false);
    stack<int> st;
    for(int i=0; i<n;i++){
        if(!visited[i]){
            topSort(i,adjList,visited,st);
        }
    }
    while(!st.empty()){
        int t=st.top();
        cout<<t<<"->";
        st.pop();
    }
    cout<<"END";

}
