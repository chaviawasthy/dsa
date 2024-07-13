#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*i+1; j++)
        {
            if (j%2==1)
            {
                cout<<"*";
            }
            else{
                cout<<i+1;
            }
        }
        cout<<endl;
    }
    
}


//second way

// #include<iostream>

// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     for (int i = 0; i < n; i++)
//     {
//         int totalcol = i+1;
//         for (int j = 0; j < totalcol; j++)
//         {
//             if (j==totalcol-1)
//             {
//                 cout<<i+1;
//             }
//             else{
//                 cout<<i+1<<"*";
//             }
//         }
//         cout<<endl;
//     }
    
// }