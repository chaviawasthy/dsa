#include<iostream>

using namespace std;

class A {
private:
    int x;

public:
    A(int a) : x(a) {} // Corrected the initialization of x in constructor

    int getX() const {
        return x;
    }
    void setX(int _val) {
        x = _val;
    }

    void print() const {
        cout << x << endl;
    }

    // friend class B;
    // friend void print(const A&);
};

// void print(const A& a) {
//     cout << a.getX() << endl;
// }

class B {
public:
    void print(const A& a) {
        // cout << a.getX() << endl; // Corrected the function call syntax
        a.print();
    }
};

int main() {
    A a(5);
    B b;
    b.print(a);
    // print(a);
    return 0;
}
