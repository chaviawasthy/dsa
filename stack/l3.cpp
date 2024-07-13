#include <bits/stdc++.h>

using namespace std;

void solve(stack<int> &st, int &pos, int &ans) {
    // Base case
    if (pos == 1) {
        ans = st.top();
        return; // Make sure to return after finding the answer
    }

    // Decrease position by 1
    pos--;

    // Take the top element out for each recursive call
    int temp = st.top();
    st.pop();

    // Recursive call
    solve(st, pos, ans);

    // No need to push back the element as the function stack unwinds
}

int getMiddleEle(stack<int> &st) {
    int size = st.size();
    if (st.empty()) {
        cout << "Stack is empty, no middle element" << endl;
        return -1;
    } else {
        // Odd
        int pos;
        if (size & 1) {
            pos = size / 2 + 1;
        } else {
            // Even
            pos = size / 2;
        }
        int ans = -1;
        solve(st, pos, ans);
        return ans;
    }
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int mid = getMiddleEle(st);
    cout << "Middle element: " << mid << endl;

    return 0;
}
