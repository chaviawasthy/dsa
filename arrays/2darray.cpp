#include<bits/stdc++.h>

using namespace std;

int main(){
    //in a 2d array you have to atleast specify the number of columns
    // int arr[3][2] = {{10,20},{30,40},{50,60}};
    // int arr1[][2] = {{10,20},{30,40},{50,60}}; //this is also valid
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    cout<<"Enter array elements:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Printing array:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}