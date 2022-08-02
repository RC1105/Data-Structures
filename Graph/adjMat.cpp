#include "bits/stdc++.h"
using namespace std;

int main(){
    int n,m;
    cout<<"No. of vertices:"; //vertices
    cin>>n;
    cout<<endl<<"No. of nodes:"; //nodes
    cin>>m;
    int adjm[n][n];
    for (int i=0; i<n+1;i++){
        for (int j=0; j<n+1;j++){
            adjm[i][j]=0;
        }
    }
    for(int i=0; i<m;i++){
        int x,y;
        cin>>x;
        cin>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
        cout<<endl;
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<adjm[i][j]<<" ";
        }
        cout<<endl;
    }
}