#include "bits/stdc++.h"
using namespace std;

void heapify(int arr[], int n, int i){
    int lar=i;
    int lft=2*i+1;
    int rt=2*i+2;
    if(arr[lar]<arr[lft] && lft<n){
        lar=lft;
    }
    if(arr[lar]<arr[rt] && rt<n){
        lar=rt;
    }
    if(lar!=i){
        swap(arr[lar],arr[i]);
        heapify(arr,n,lar);
    }
}
void heapSort(int arr[],int n){
    for(int i=(n/2-1);i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1; i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}
int main(){
    int arr[]={7,4,2,1,3};
    heapSort(arr,5);
    for(int i=0; i<5;i++){
        cout<<arr[i];
    }
    return 0;
}
