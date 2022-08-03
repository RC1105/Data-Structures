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
    vector<int> parent(n,-1);
    q.push(1);
    visited[1]=true;
    while(!q.empty()){
        int f=q.front();
        cout<<f<<"-> ";
        q.pop();
        for(auto itr=adjList[f].begin();itr!=adjList[f].end();itr++){
            if(!visited[*itr]){
                q.push(*itr);
                parent[*itr]=f;
                visited[*itr]=true;
            }
        }
    }
    cout<<endl;
    int src=1;
    int des=8;
    int ans=8;
    vector<int> vec;
    vec.push_back(ans);
    while(ans!=src){
        ans=parent[ans];
        vec.push_back(ans);
    }
    for(int i=vec.size()-1; i>=0;i--){
        cout<<vec[i]<<" ";
    }
}