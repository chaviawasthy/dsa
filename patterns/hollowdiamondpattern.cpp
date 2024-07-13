#include<iostream>

using namespace std;

int main(){
    int num;
    cin>>num;

    int n = 2*num;
    //upper half
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            cout<<" ";
        }
        for (int j = 0; j < i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
    

    //lower half
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<" ";
        }
        for (int j = 0; j < n-i-1; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
    
}