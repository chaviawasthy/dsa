#include<iostream>

using namespace std;

void countZeroOne(int arr[], int n){
    int count0 = 0;
    int count1 = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count0++;
        }
        else{
            count1++;
        }
    }
    cout<<"Number of 0s: "<<count0<<endl;
    cout<<"Number of 1s: "<<count1<<endl;
}

int main(){
    int arr[] = {0,0,0,1,1,0,1,0,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    countZeroOne(arr, size);
    return 0;

}