#include "bits/stdc++.h"
using namespace std;

void heapify(int arr[], int n, int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void deleteR (int arr[], int &n){
    arr[0]=arr[n-1];
    n=n-1;
    heapify(arr,n,0);
}
int main(){
    int MAX=11;
    int n=5;
    int arr[MAX]={10,4,3,2,4};
    deleteR(arr,n);
}