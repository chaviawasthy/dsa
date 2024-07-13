#include<bits/stdc++.h>

using namespace std;

int fastExponentiation(int a, int b){  //O(logb)
    int ans = 1;
    while(b>0){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b = b>>1;
    }
    return ans;
}

int slowExponentiation(int a, int b){
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}

int main(){
    cout<<slowExponentiation(2, 10)<<endl;
    cout<<fastExponentiation(2, 10)<<endl;
    return 0;
}