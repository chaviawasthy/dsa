#include<bits/stdc++.h>

using namespace std;

int main(){

    //min heap creation
    priority_queue <int, vector<int>, greater<int>> pq;
    //insertion
    pq.push(100);
    pq.push(90);
    pq.push(70);

    cout<<"Top element of heap: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element of heap: "<<pq.top()<<endl;
    cout<<"Size: "<<pq.size()<<endl;
    if (pq.empty())
    {
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }

    return 0;
}