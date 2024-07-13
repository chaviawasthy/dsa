#include<bits/stdc++.h>

using namespace std;

int main(){
    //create max heap
    priority_queue<int> pq;
    //insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout<<"Top element of Heap: "<<pq.top()<<endl;
    pq.pop();

    cout<<"Top element of Heap: "<<pq.top()<<endl;
    cout<<"Size of max heap: "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }

    return 0;
}