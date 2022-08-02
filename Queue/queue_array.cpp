#include <iostream>
using namespace std;
#define n 20
class queue{
    int *arr;
    int front;
    int back;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;

    }
    void push( int x){
        if (back==n-1){
            cout<<"No space to accomodate ur new friend";
            return;
        }
        else{
            if (front==-1){
                front++;
                
            }
            back++;
            arr[back]=x;
        }
    }
    void pop(){
        if (back<front || front==-1){
            cout<<"Queue is already Empty";
            return;
        }
        else{
            front++;
        }

    }

    int peek(){
        if (back<front || front==-1){
            cout<<"Queue is Empty\n";
            return -1;
            
        }
        else{
            return arr[front];
        }

    }
    bool empty(){
        if (back<front || front==-1){
            
            return true;
        }
        return false;

    }
};

int main(){
    queue q1;
    q1.push(7);
    q1.push(8);
    cout<<q1.peek();
    cout<<endl;
    q1.pop();
    cout<<q1.peek();
    cout<<endl;
    q1.pop();
    cout<<q1.peek();
    cout<<endl;
    cout<<q1.empty();
    return 0;
}
