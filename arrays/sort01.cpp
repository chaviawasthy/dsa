#include<iostream>

using namespace std;

void sortZeroOne(int arr[], int n){
    int zeroCount = 0;
    int oneCount = 0;
    // for(int i=0;i<n;i++){
    //     if(arr[i] == 0){
    //         zeroCount++;
    //     }
    //     else{
    //         oneCount++;
    //     }
    // }
    // int i;
    // for(i=0;i<zeroCount;i++){
    //     arr[i] = 0;
    // }
    // for(int j=i;j<n;j++){
    //     arr[j] = 1;
    // }


    //easy way
    int index = 0;
    while(zeroCount--){
        // arr[index++] = 0; or
        arr[index] = 0;
        index++;
    }

    while(oneCount--){
        // arr[index++] = 1; or
        arr[index] = 1;
        index++;
    }
}

int main(){
    int arr[] = {0,1,0,1,1,1,0,0,0,1,0,1,1,0,1};
    int n = 15;

    sortZeroOne(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}