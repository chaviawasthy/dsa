#include<bits/stdc++.h>

using namespace std;

void diagonalSum(int arr[][4], int rows, int cols){
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += arr[i][i];
    }
    cout<<"Sum of diagonal elements is: "<<sum<<endl;
}

int main(){
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int rows = 3, cols = 4;
    diagonalSum(arr,rows,cols);
    return 0;

}