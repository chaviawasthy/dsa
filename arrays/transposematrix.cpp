#include<bits/stdc++.h>

using namespace std;

void transposeMatrix(int arr[][4], int rows, int cols){
    // int transpose[cols][rows];
    // for (int i = 0; i < cols; i++)
    // {
    //     for (int j = 0; j < rows; j++){
    //         transpose[i][j] = arr[j][i];
    //     }
    // }
    // cout<<"Transpose of the matrix is: "<<endl;
    // for (int i = 0; i < cols; i++)
    // {
    //     for (int j = 0; j < rows; j++){
    //         cout<<transpose[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //or
    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < cols; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void printArray(int arr[][4], int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int rows = 3, cols = 4;
    transposeMatrix(arr,rows,cols);
    cout<<"Transpose of the matrix is: "<<printArray<<endl;
    return 0;

}