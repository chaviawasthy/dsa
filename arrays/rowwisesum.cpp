#include<bits/stdc++.h>

using namespace std;

void rowWiseSum(int arr[][4], int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++){
            sum += arr[i][j];
        }
        cout<<"Sum of row "<<i+1<<" is: "<<sum<<endl;
    }
}

int main(){
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int rows = 3, cols = 4;
    rowWiseSum(arr,rows,cols);
    return 0;

}