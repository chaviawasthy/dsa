#include<iostream>

using namespace std;

int main(){
    int n = 3;
    int &a = n;
    int &b = n;

    cout<<a<<endl;
    cout<<b<<endl;

    a++;
    cout<<a<<endl;
    cout<<b<<endl;

    return 0;
}