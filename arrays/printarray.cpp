#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[5];
    int n = 5;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Printing the array: "<<endl;
    printArray(arr, n);
}