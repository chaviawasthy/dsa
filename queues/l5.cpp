#include <bits/stdc++.h>
using namespace std;

class Deque {
public:
    int *arr;
    int front, rear, size;

    Deque(int size) {
        arr = new int[size];
        this->size = size;
        front = rear = -1;
    }

    void pushFront(int val) {
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) {
            cout << "Overflow" << endl;
            return;
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
            arr[front] = val;
        } else if (front == 0) {
            front = size - 1;
            arr[front] = val;
        } else {
            front--;
            arr[front] = val;
        }
    }

    void pushBack(int val) {
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) {
            cout << "Overflow" << endl;
            return;
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
            arr[rear] = val;
        } else if (rear == size - 1) {
            rear = 0;
            arr[rear] = val;
        } else {
            rear++;
            arr[rear] = val;
        }
    }

    void popFront() {
        if (front == -1 && rear == -1) {
            cout << "Underflow" << endl;
            return;
        }
        if (front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            arr[front] = -1;
            front = 0;
        } else {
            arr[front] = -1;
            front++;
        }
    }

    void popBack() {
        if (front == -1 && rear == -1) {
            cout << "Underflow" << endl;
            return;
        }
        if (front == rear) {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            arr[rear] = -1;
            rear = size - 1;
        } else {
            arr[rear] = -1;
            rear--;
        }
    }
};

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_front(20);
    // dq.pop_back();
    dq.pop_front();

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    cout<<dq.size()<<endl;
    return 0;
}
