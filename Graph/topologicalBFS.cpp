#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,m;
    cout<<"No. of vertices:"; //vertices
    cin>>n;
    cout<<endl<<"No. of nodes:"; //nodes
    cin>>m;
    vector<vector<int>> adjList(n);
    vector<int> indeg(n);
    for(int i=0; i<m;i++){
        int x,y;
        cin>>x;
        cin>>y;
        adjList[x].push_back(y);
        indeg[y]++;
    }
    queue<int> q;
    for(int i=0; i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int k=q.front();
        cout<<k<<"->";
        q.pop();
        for(auto itr: adjList[k]){
            indeg[itr]--;
            if(indeg[itr]==0){
                q.push(itr);
            }
        }
    }
    return 0;

}
