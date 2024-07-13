#include<iostream>

using namespace std;

void fun(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n]; //each element would be 0, or default value
    //taking n elements input and inserting in array
    for (int i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        arr[i] = data;
    }
    //let's try inserting mor4e items
    arr[n] = 80;

    fun(arr, n);

    return 0;
}