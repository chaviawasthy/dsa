#include<bits/stdc++.h>

using namespace std;

void shiftNegatives(int arr[], int n){
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<0){
            if(i!=j){
                swap(arr[i],arr[j]);
            }
            j++;
        }
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,-1,-2,-3,-4,-5};
    int n = 10;
    
    shiftNegatives(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}