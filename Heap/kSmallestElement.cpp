#include "bits/stdc++.h"
using namespace std;

int kSmallestElement(int arr[], int l , int r, int k){
    priority_queue<int> pq; // max heap
    for(int i=0; i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<r;i++){
        if(pq.top()>arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    int arr[6]={7,4,0,6,8,5};
    cout<<kSmallestElement(arr,0,6,4);
    return 0;
}
