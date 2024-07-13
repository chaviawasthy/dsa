#include<bits/stdc++.h>
using namespace std;

bool findTarget(int arr[][4],int rows,int cols,int target){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int rows = 3, cols = 4;
    int target = 7;
    cout<<"Found or not: "<<findTarget(arr, rows, cols, target)<<endl;
    return 0;

}