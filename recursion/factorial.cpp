#include<bits/stdc++.h>

using namespace std;

int factorial(int n){
    //base case
    if (n==1)
    {
        return 1;
    }
    if (n==0)
    {
        return 1;
    }

    //recursive relation
    int ans = factorial(n-1);

    //processing
    int finalans = n*ans;
    return finalans;
    
}

int main(){
    cout<<factorial(5)<<endl;
    return 0;
}