#include<bits/stdc++.h>

using namespace std;

int main() {
    //creation
    queue<int> q;

    //insertion
    q.push(1);

    //remove
    q.pop();

    //size
    cout << "Size of Queue: " << q.size() << endl;

    //empty
    if (q.empty() == true) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    q.push(10);
    q.push(20);
    q.push(30);

    //front
    cout << "Front element: " << q.front() << endl;

    //back
    cout << "Back element: " << q.back() << endl;
    return 0;
}