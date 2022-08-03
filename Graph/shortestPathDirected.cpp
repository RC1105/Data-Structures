#include "bits/stdc++.h"
using namespace std;
unordered_map <int, list<pair<int,int>>> adj;
void addEdge(int u, int v, int w){
    pair<int,int> p=make_pair(v,w);
    adj[u].push_back(p);
}

void printAdj(){
    for(auto itr: adj){
        cout<< itr.first<<" ->";
        for(auto itr2: itr.second){
            cout<<"("<<itr2.first<<","<<itr2.second<<")";
        }
        cout<<endl;
    }
}

void dfs(int node, vector<bool> & vis, stack<int> &s){
    vis[node]=true;
    for(auto itr: adj[node]){
        if(!vis[itr.first]){
            dfs(itr.first,vis,s);
        }
    }
    s.push(node);
}
void getPath(vector<int> &dis, int src, stack<int> &s){
    dis[src]=0;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        if(dis[t]!=INT_MAX){
            for(auto itr: adj[t]){
                if( dis[t]+itr.second <dis[itr.first]){
                    dis[itr.first]=dis[t]+itr.second;
                }
            }
        }
    }
}

int main(){
    addEdge(0,1,5);
    addEdge(0,2,3);
    addEdge(1,2,2);
    addEdge(1,3,6);
    addEdge(2,3,7);
    addEdge(2,4,4);
    addEdge(2,5,2);
    addEdge(3,4,-1);
    addEdge(4,5,-2);
    int n=6;
    printAdj();
    vector<bool> vis(n);
    stack<int> s;
    for(int i=0; i<n;i++){
        if(!vis[i]){
            dfs(i,vis,s);
        }
    }
    int src=1;
    vector <int> dist(n,INT_MAX);
    getPath(dist,src,s);

    for(int i=0; i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}