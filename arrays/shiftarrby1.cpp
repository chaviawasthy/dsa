#include<bits/stdc++.h>

using namespace std;

void shiftArray(int arr[], int n){
    int temp = arr[n-1];
    for(int i=n-1;i>=1;i--){
        arr[i] = arr[i-1];
    }

    arr[0] = temp;

}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int n = 6;

    shiftArray(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}