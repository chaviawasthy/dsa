#include<iostream>

using namespace std;

int main(){
    int a = 5;
    int b = 10;

    cout<<(a&b)<<endl;
    cout<<(a|b)<<endl;
    cout<<(a^b)<<endl;
    cout<<(~a)<<endl;

    
    //left shift
    cout<<(a<<1)<<endl;

    //right shift
    cout<<(a>>1)<<endl;

    //pre increment
    cout<<++a<<endl;

    //post increment
    cout<<a++<<endl;

    //pre decrement
    cout<<--a<<endl;

    //post decrement
    cout<<a--<<endl;
    
    return 0;

}