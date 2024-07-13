#include<bits/stdc++.h>

using namespace std;

int main(){
    int a = 5;
    cout<<a<<endl;
    cout<<"Address of a: "<<&a<<endl;


    int *p = &a;
    cout<<"Accessing a using pointer: "<<*p<<endl;

    char ch = 'a';
    char *c = &ch;
    cout<<c;

    itn arr[5] = {1,2,3,4,5};
    int * ptr1 = arr; //will give address of first element of array
    int *ptr = &arr; //will give error
    int(*ptr)[5] = &arr; //correct way to declare pointer to array

    char ch[10] = "Chavi";
    char *cptr = &ch;


    return 0;
}