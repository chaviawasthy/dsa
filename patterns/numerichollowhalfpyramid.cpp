#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            if (col==0 || col==row || row==n-1)
            {
                cout<<col+1;
            }
            cout<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}