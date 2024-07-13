#include<bits/stdc++.h>

using namespace std;

int main(){
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