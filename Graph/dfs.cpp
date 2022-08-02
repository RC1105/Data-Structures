#include "bits/stdc++.h"
using namespace std;

vector<int> adjList[1000];
vector<bool> vis(10000,false);

void dfs(int i){
    vis[i]=true;
    cout<<i<<"-> ";
    for(auto itr=adjList[i].begin(); itr!=adjList[i].end();itr++){
        if(vis[*itr]!=true){
            dfs(*itr);
        }
    }
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    for(int i=0; i<m;i++){
        int x,y;
        cin>>x>>y;
        adjList[y].push_back(x);
        adjList[x].push_back(y);
    }
    dfs(0);
    return 0;
}
