#include<iostream>

using namespace std;

long long int fact(long long int n){
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact*i;
    }
    
    return fact;
}

int main(){
    long long int n;
    cin>>n;
    
    long long int factorial = fact(n);
    cout<<factorial<<endl;
    return 0;
}


//big numbers like 45 tc they can't be stored in int so we use long long int