#include<bits/stdc++.h>

using namespace std;

class Queue {
    public:
    int *arr;
    int front, rear, size;

    Queue(int size){
        arr = new int[size];
        this->size = size;
        front = rear = -1;
    }

    void push(int val) {
        //check full
        if(rear == size - 1){
            cout << "Queue is full" << endl;
            return;
        }
        else if(front == -1 && rear == -1){
            //not full
            front++;
            rear++;
            arr[rear] = val;
        }
        else {
            //normal case
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        //underflow
        if(front == -1 && rear == -1){
            cout<<"Que underflow"<<endl;
            return;
        }
        else if(front == rear){
            //only one element
            arr[front] = -1;
            front = rear = -1;
        }
        else {
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    
    }

    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        }
        return rear - front + 1;
    }

    int getFront(){
        if(front == -1 && rear == -1){
            cout<<"No element in queue, cannot give front element"<<endl;
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(front == -1 && rear == -1){
            cout<<"No element in queue, cannot give rear element"<<endl;
            return -1;
        }
        return arr[rear];
    }

    void print(){
        cout<<"Priniting Queue"<<endl;
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    //create a queue
    Queue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();
    
    cout<<"Size of queue: "<<q.getSize()<<endl;

    q.pop();
    q.print();

    cout<<"Size of queue: "<<q.getSize()<<endl;
    cout<<"Queue is empty or not: "<<q.isEmpty()<<endl;

    q.push(100);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    cout<<q.getFront()<<endl;
    q.pop();q.print();

    cout<<q.getSize()<<endl;

    return 0;
}