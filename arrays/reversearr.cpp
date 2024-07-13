#include<iostream>

using namespace std;

void reverseArray(int arr[], int size){
    int left = 0;
    int right = size-1;
    // while(left<=right){
    //     swap(arr[left], arr[right]);
    //     left++;
    //     right--;
    // }
    //or
    for(int left = 0;right = size-1;left<=right;left++,right--){
        swap(arr[left], arr[right]);
    }

    //printing the reversed array
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int size = 6;

    reverseArray(arr, size);
}