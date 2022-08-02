#include "bits/stdc++.h"
using namespace std;

void heapify(int arr[],int n, int i){
    int parent= (i-1)/2;
    if(arr[parent]>0){
        if(arr[i]>arr[parent]){
            swap(arr[i],arr[parent]);
            heapify(arr,n,parent);
        }
    }
}
void insert(int arr[], int &n, int key){
    n=n+1;
    arr[n-1]=key;
    heapify(arr,n,n-1);

}
int main(){
    int MAX=11;
    int n=5;
    int arr[MAX]={10,4,3,2,4};
    insert(arr,n,7);
    return 0;
}
