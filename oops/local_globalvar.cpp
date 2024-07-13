#include<iostream>

using namespace std;

int x = 2; //global variable

void fun(){
    int x = 10; //local variable
    cout << "local x: " << x << endl;
    cout << "global x: " << ::x << endl; //:: is scope resolution operator
}

int main(){
    ::x = 5; //changing global variable
    int x = 20; //local variable
    cout << "local x: " << x << endl;
    cout << "global x: " << ::x << endl;

    {
        int x = 30; //local variable
        {
            int x = 40; //local variable
            cout << "local x: " << x << endl;
            cout << "global x: " << ::x << endl;
        
        }
        cout << "local x: " << x << endl;
        cout << "global x: " << ::x << endl;
    }
    fun();

    return 0;
}