#include<iostream>

using namespace std;

inline void numShow(int num){
    cout << "The number is " << num << endl;
}

int main(){

    numShow(5);
    numShow(6);
    numShow(7);
    numShow(8);
    numShow(9);
    numShow(10);  //inline function is called 6 times

    return 0;
}