#include<iostream>

using namespace std;

int main() {
    const int x = 5;
    cout<<x<<endl;
//intialisation can be done but we cannot change the value of x
    // x = 10; //error: assignment of read-only variable 'x'
    // cout<<x<<endl;

    //const with pointers
    // int *a = new int;
    // *a = 2;
    // cout<<*a<<endl;
    // delete a;
    // int b = 3;
    // a = &b;
    // cout<<*a<<endl;

    // const int *a = new int(2); //const, data, non const pointer
    // // or int const *a = new int(2);
    // cout<<*a<<endl;
    // int b = 20;
    // a = &b; //pointer itself can be reassigned
    // cout<<*a<<endl;
    // *a = 20; // can't change the content of the pointer
    // cout<<*a<<endl; // compilation error dega
    // delete a;
    // int b = 3;
    // a = &b;
    // cout<<*a<<endl;

    //const pointer but non const data
    // int * const a = new int(2);
    // cout<<*a<<endl;
    // *a = 20;//chal jayega
    // cout<<*a<<endl;
    // int b = 25;
    // a = &b; //nahi chalega, const pointer hai
    // cout<<*a<<endl;

    //const pointer & const data
    const int * const a = new int(2);
    cout<<*a<<endl;
    *a = 20; //nahi chalega
    int b = 25;
    a = &b; //nahi chalega
    return 0;
}