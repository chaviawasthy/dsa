#include<iostream>
using namespace std;

int main(){
    int num = 8;
    int n = 4;

    //upper half
    for (int i = 0; i < n; i++)
    {
        //inverted pyramid 1
        for (int j = 0; j < n-i; j++)
        {
            cout<<"*";
        }
        //full pyramid 1
        for (int j = 0; j < 2*i+1; j++)
        {
            cout<<" ";
        }
        //inverted pyramid 2
        for (int j = 0; j < n-i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
        
    }


    //lower half    
    for (int i = 0; i < n; i++)
    {
        //inverted pyramid 1
        for (int j = 0; j < i+1; j++)
        {
            cout<<"*";
        }
        //full pyramid 1
        for (int j = 0; j < 2*(n-i)-1; j++)
        {
            cout<<" ";
        }
        //inverted pyramid 2
        for (int j = 0; j < i+1; j++)
        {
            cout<<"*";
        }
        cout<<endl;
        
    }
    
}