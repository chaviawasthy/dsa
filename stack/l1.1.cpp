#include<iostream>
using namespace std;

class Stack {
    public:
    int* arr;
    int size;
    int top;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data) {
        if(top == size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    void pop() {
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        else{
            top--;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }

    int getTop() {
        return arr[top];
    }

    int getSize() {
        return top+1;
    }

    void print(){
        cout<<"Top: "<<getTop()<<endl;
        cout<<"Stack: ";
        for(int i=0; i<getSize(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Stack s(3);
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.getTop()<<endl;
    s.pop();
    cout<<s.getTop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

    // Stack st(8);
    // st.push(10);
    // st.print();
    // st.push(20);
    // st.print();
    // st.push(30);
    // st.print();

    return 0;
}