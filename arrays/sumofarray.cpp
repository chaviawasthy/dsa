#include<iostream>

using namespace std;

int main(){
    int arr[5];
    int n = 5;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    cout<<"Sum of the array: "<<sum<<endl;
}