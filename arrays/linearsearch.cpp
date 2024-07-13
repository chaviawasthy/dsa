#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target element: "<<endl;
    cin>>target;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"Element found at index: "<<i<<endl;
            break;
        }
        else if(i==n-1){
            cout<<"Element not found"<<endl;
        }
    }
    return 0;
}

//or

// #include<iostream>

// using namespace std;

// bool linearSearch(int arr[], int n, int target){
//     for(int i=0;i<n;i++){
//         if(arr[i]==target){
//             return true;
//         }
//     }
//     return false;
// }

// int main(){
//     int n;
//     cout<<"Enter the size of the array: "<<endl;
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the elements of the array: "<<endl;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int target;
//     cout<<"Enter the target element: "<<endl;
//     cin>>target;
//     bool found = linearSearch(arr, n, target);
//     if(found){
//         cout<<"Element found"<<endl;
//     }
//     else{
//         cout<<"Element not found"<<endl;
//     }
//     return 0;
// }