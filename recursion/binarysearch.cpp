#include<bits/stdc++.h>

using namespace std;

int binSearch(int arr[], int s, int e, int target){
    //base case
    if (s>e)
    {
        //element not found
        return -1;
    }
    int mid = s+(e-s)/2;
    if(arr[mid]==target){
        return mid;
    }
    //now recursively call the function
    if(arr[mid]<target){
        //move right
        return binSearch(arr, mid+1, e, target);
    }
    else{
        //move left
        return binSearch(arr, s, mid-1, target);
    }
    
}

int main(){
    int arr[] = {10,20,30,40,50,60,70,80};
    int size = 8;
    int start = 0;
    int end = size-1;

    int target = 80;

    int found = binSearch(arr, start, end, target);
    if(found!=-1){
        cout<<"Target found at index: "<<found<<endl;
    }
    else{
        cout<<"Target not found at index: "<<found<<endl;
    }
}