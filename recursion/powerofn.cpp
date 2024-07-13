#include<bits/stdc++.h>

using namespace std;

int pow(int n){
    //base case
    if (n==0)
    {
        return 1;
    }
    int ans = 2*pow(n-1);
    return ans;
}

int main(){
    cout<<pow(10)<<endl;
    return 0;
}