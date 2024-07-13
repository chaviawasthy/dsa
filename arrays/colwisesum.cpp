#include<bits/stdc++.h>

using namespace std;

void colWiseSum(int arr[][4], int rows, int cols){
    for (int i = 0; i < cols; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++){
            sum += arr[j][i];
        }
        cout<<"Sum of column "<<i+1<<" is: "<<sum<<endl;
    }
}

int main(){
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int rows = 3, cols = 4;
    colWiseSum(arr,rows,cols);
    return 0;

}