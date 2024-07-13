#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        int C = 1;
        for(int j=1;j<=i;j++){
            cout<<C<<" ";
            C = C * (i-j)/j;
        }
        cout<<endl;
    }
    return 0;
}