#include<bits/stdc++.h>

using namespace std;

bool searchArray(int arr[], int size, int target, int index){
    //base case
    if(index>=size) return false;
    if(arr[index]==target) return true;

    //recursive call
    bool aageKISearch = searchArray(arr, size, target, index+1);
    return aageKISearch;
}

int main(){
    int arr[] = {1,2,3,4,5};
    cout<<"Target found or not: "<<searchArray(arr, 5, 3, 0)<<endl;
    return 0;
}