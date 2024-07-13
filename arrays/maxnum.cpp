#include<bits/stdc++.h>
using namespace std;

int findMax(int arr[][4],int rows,int cols){
    int max = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++){
            if(arr[i][j] > max){
                max = arr[i][j];
            }
        }
    }
    return max;
}

int findMin(int arr[][4],int rows,int cols){
    int min = INT_MAX;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++){
            if(arr[i][j] < min){
                min = arr[i][j];
            }
        }
    }
    return min;
}

int main(){
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int rows = 3, cols = 4;
    cout<<"Max element: "<<findMax(arr,rows,cols)<<endl;
    cout<<"Min element: "<<findMin(arr,rows,cols)<<endl;
    return 0;

}