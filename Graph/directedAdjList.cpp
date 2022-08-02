#include "bits/stdc++.h"
using namespace std;
const int N=1e5+2;
vector<int> adjList[N];

int main(){
    int n,m;
    cout<<"No. of vertices:"; //vertices
    cin>>n;
    cout<<endl<<"No. of nodes:"; //nodes
    cin>>m;
    for(int i=0; i<m;i++){
        int x,y;
        cin>>x;
        cin>>y;
        adjList[x].push_back(y);
    }
    cout<<"ADJ LIST FOR DIRECTED GRAPH"<<endl;
    for(int i=0; i<n;i++){
        cout<<"("<<i<<")->";
        for(auto itr=adjList[i].begin(); itr!=adjList[i].end();itr++){
            cout<<*itr<<"->";
        }
        cout<<"END";
        cout<<endl;
    }
    
    return 0;
}
