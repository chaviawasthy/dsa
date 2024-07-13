#include<bits/stdc++.h>

using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if (top2 - top1 == 1)
        {
            //no space available
            cout<<"Stack overflow"<<endl;
        }
        else{
            top1++
            arr[top1] = data;
        }
    }

    void push2(int data){
        if (top2 - top1 == 1)
        {
            //no space available
            cout<<"Stack overflow"<<endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }

    int pop1(){
        if(top1 == -1){
            cout<<"Stack underflow"<<endl;
        }
        else{
            arr[top1] = 0;
            top1--;
        }
    }

    int pop2(){
        if(top2 == size){
            cout<<"Stack underflow"<<endl;
        }
        else{
            arr[top2] = 0;
            top2++;
        }
    }

    void print() {
        cout<<endl;
        cout<<"Top1: "<<top1<<endl;
        cout<<"Top2: "<<top2<<endl;
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Stack s(6);
    s.print();

    s.push1(10);
    s.print();

    s.push1(20);
    s.print();

    s.push2(100);
    s.print();

    s.push2(200);
    s.print();

    s.push2(300);
    s.print();

    s.push2(400);
    s.print();

    s.push1(40);
    s.pop1();
    s.print();

    s.pop1();
    s.print();

    s.pop1();
    s.print();


    return 0;
}