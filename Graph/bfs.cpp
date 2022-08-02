#include "bits/stdc++.h"
using namespace std;
vector<int> adjList[1000];
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
    queue<int> q;
    vector<bool> visited(n,false);
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int f=q.front();
        cout<<f<<"-> ";
        q.pop();
        for(auto itr=adjList[f].begin();itr!=adjList[f].end();itr++){
            if(!visited[*itr]){
                q.push(*itr);
                visited[*itr]=true;
            }
        }
    }
    return 0;
}
