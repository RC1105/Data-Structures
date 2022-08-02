#include "bits/stdc++.h"
using namespace std;
bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &vis, int parent){
    vis[src]=true;
    for(auto i: adj[src]){
        if(i!=parent){       
            if(vis[i]==true){
                return true;
            }
            if(!vis[i] && isCycle(i,adj,vis,src)){
                return true;
            }
        }
    }
    return false;
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
        adjList[y].push_back(x);
    }
    bool ans=false;
    vector<bool> vis(n,false);
    for(int i=0; i<n;i++){
        if(!vis[i] && isCycle(i,adjList,vis,-1)){
            ans=true;
        }
    }
    cout<<ans;
}