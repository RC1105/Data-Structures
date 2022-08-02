#include "bits/stdc++.h"
using namespace std;
class MyCircularDeque {
public:
    int *arr ;
    int front, rear;
    int n;
    int maxx;
    MyCircularDeque(int k) {
        arr = new int[k];
        maxx = k;
        n = 0;
        front = 0;
        rear = maxx - 1;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = ((front - 1) + maxx) % maxx;
        arr[front] = value;
        n++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1)% maxx;
        arr[rear] = value;
        n++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % maxx;
        
        n--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = ((rear - 1) + maxx) % maxx;
        n--;
        return true;
    }
    
    int getFront() {
        return isEmpty()? -1 : arr[front];
    }
    
    int getRear() {
        return isEmpty()? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return n == 0;
    }
    
    bool isFull() {
        return n == maxx;
    }
};
int main(){
    MyCircularDeque* obj = new MyCircularDeque(4);
    bool one = obj->insertFront(7);
    bool two = obj->insertLast(8);
    bool three = obj->insertLast(9);
    bool four = obj->insertLast(10);
    bool five = obj->deleteFront();
    bool six = obj->deleteLast();
    int seven = obj->getFront();
    int eight= obj->getRear();
    bool nine = obj->isEmpty();
    bool ten = obj->isFull();
    cout<<one<<endl<<two<<endl<<three<<endl<<four<<endl<<five<<endl<<six<<endl<<seven<<endl<<eight<<endl<<nine<<endl<<ten;
}