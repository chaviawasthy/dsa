#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        //spaces
        for (int j = 0; j < i; j++)
        {
            cout<<" ";
        }
        //stars
        int totalcol = n-i;
        for (int j = 0; j < totalcol; j++)
        {
            if (j==0 || j==totalcol-1)
            {
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
        
    }
    
}