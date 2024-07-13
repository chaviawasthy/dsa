#include<iostream>

using namespace std;

int main(){
    int arr[5];
    char ch[26];
    bool flags[3];
    long num[10];
    short int val[100];

    cout<<"An array has been created successfully"<<endl;

    int a = 30;
    cout<<"Address of a: "<<&a<<endl;
    cout<<"Size of a: "<<sizeof(a)<<endl;

    int a1[3];
    cout<<"Address of a1: "<<&a1<<endl;
    cout<<"Size of a1: "<<sizeof(a1)<<endl;

    return 0;
}