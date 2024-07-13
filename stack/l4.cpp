#include<bits/stdc++.h>

using namespace std;

void insertAtBottom(stack<int> &s, int &element) {
    //base case
    if (s.empty()) {
        s.push(element);
        return;
    }
    //1 case
    int topElement = s.top();
    s.pop();

    //recursive case
    insertAtBottom(s, element);
    s.push(topElement);
}

void reverseStack(stack<int> &s) {
    //base case
    if (s.empty()) {
        return;
    }
    //1 case
    int element = s.top();
    s.pop();

    //recursive case
    reverseStack(s);
    insertAtBottom(s, element);
}

void insertSorted(stack<int> &s, int &element) {
    //base case
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }
    //1 case
    int topElement = s.top();
    s.pop();

    //recursive case
    insertSorted(s, element);
    s.push(topElement);
}

void sortStack(stack<int> &s) {
    //base case
    if (s.empty()) {
        return;
    }
    //1 case
    int element = s.top();
    s.pop();

    //recursive case
    sortStack(s);
    insertSorted(s, element);
}

int main() {
    stack<int> s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // int element = 400;
    // cout<<"Without reversing: "<<endl;
    // cout<<" 30 20 10"<<endl;
    // insertAtBottom(s, element);
    // reverseStack(s);

    // cout<<"With reversing: "<<endl;

    // while (!s.empty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    // cout<<"Before sorting: "<<endl;
    // cout<<" 30 20 10"<<endl;

    // int element = 25;
    // insertSorted(s, element);

    // cout<<"After sorting: "<<endl;
    // while (!s.empty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    stack<int> st;
    st.push(10);
    st.push(7);
    st.push(12);
    st.push(5);
    st.push(11);

    sortStack(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}