#include "bits/stdc++.h"
using namespace std;
bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &vis, int parent,vector<bool> &dfsvis){
    dfsvis[src]=true;
    vis[src]=true;
    for(auto i: adj[src]){ 
        if(!vis[i] && isCycle(i,adj,vis,src,dfsvis)){
            return true;
        }
        if(dfsvis[i]==true){
            return true;
        }
    }
    dfsvis[src]=false;
    return false;
}
int main(){
    int n,m;
    cout<<"No. of vertices:"; //vertices
    cin>>n;
    cout<<endl<<"No. of nodes:"; //nodes
    cin>>m;
    vector<vector<int>> adjList(n);
    vector<bool> dfsVisa(n,false);
    for(int i=0; i<m;i++){
        int x,y;
        cin>>x;
        cin>>y;
        adjList[x].push_back(y);
        //adjList[y].push_back(x);
    }
    bool ans=false;
    vector<bool> vis(n,false);
    for(int i=0; i<n;i++){
        if(!vis[i] && isCycle(i,adjList,vis,-1,dfsVisa)){
            ans=true;
        }
    }
    if(ans==true){
        cout<<"CYCLE PRESENT";
    }
    else{
        cout<<"No cycle Present";
    }
}