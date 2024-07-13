#include<bits/stdc++.h>

using namespace std;

void checkEvenOdd(int n){
    if (n & 1)
    {
        cout<<"Odd"<<endl;
    }
    else{
        cout<<"Even"<<endl;
    }
    
}

int main(){
    int n = 19;
    checkEvenOdd(n);

    return 0;
}