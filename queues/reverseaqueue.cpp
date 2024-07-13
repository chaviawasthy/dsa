#include<bits/stdc++.h>

using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> s;
    //one by one queue elements are pushed into stack
    while(!q.empty()){
        int frontElement = q.front();
        q.pop();

        s.push(frontElement);
    }

    //pop from stack and push it back to queue
    while(!s.empty()){
       int element = s.top();
       s.pop();
       
       q.push(element);
    }
}   

//using recursion
void reverseUsingRecursion(queue<int> &q){
    if(q.empty()){
        return;
    }

    int frontElement = q.front();
    q.pop();

    reverseUsingRecursion(q);

    q.push(frontElement);
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    // reverseQueue(q);
    reverseUsingRecursion(q);

    cout<<"Printing the reversed queue: "<<endl;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        cout<<element<<" ";
    }

    return 0;
}