#include<bits/stdc++.h>

using namespace std;

int main() {
    string str = "Hello World"; 
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        s.push(str[i]);
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout<<endl;

    return 0;
}
