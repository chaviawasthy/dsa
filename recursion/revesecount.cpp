#include<bits/stdc++.h>

using namespace std;

void print(int n){
    //base case
    if (n==1)
    {
        cout<<1<<" ";
        return;
    }
    //processing
    cout<<n<<" ";
    //recursion call
    print(n-1);
    //agar iss code me mai print pehle likhte aur cout baadme toh count 1 se chalta 
}

int main(){
    print(5);
}