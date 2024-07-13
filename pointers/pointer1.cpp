// #include<bits/stdc++.h>

// using namespace std;

// void solve(int *arr, int size){
//     cout<<"Size of array inside func: "<<sizeof(arr)<<endl;
// }

// int main(){
//     int arr[] = {1,2,3,4,5};
//     cout<<"Size of array: "<<sizeof(arr)<<endl;
//     solve(arr,5);
// }

// also part 2
#include<bits/stdc++.h>
using namespace std;

void func(int* p){
    p = p+1;
}

void func2(int* &p){
    p = p+1;
}

int main(){
    int a  = 5;
    int *p = &a;

    cout<<"p: "<<p<<endl;
    cout<<"&p: "<<&p<<endl;
    cout<<"*p: "<<*p<<endl;
    func(p);
    cout<<"p: "<<p<<endl;
    cout<<"&p: "<<&p<<endl;
    cout<<"*p: "<<*p<<endl;
    func2(p);
    cout<<"p: "<<p<<endl;
    cout<<"&p: "<<&p<<endl;
    cout<<"*p: "<<*p<<endl;

    return 0;
}