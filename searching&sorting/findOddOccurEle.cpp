#include<iostream>

using namespace std;

int findOddOccuringElement(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(s==e){
            return s;
        }
        if(mid&1){
            if(mid-1>=0 && arr[mid-1] == arr[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        else{
            if(mid+1<n && arr[mid]==arr[mid+1]){
                s = mid+2;
            }
            else{
                e = mid;  //e=mid-1 se answer loat ho sakta hai
            }
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    int arr[] = {10,10,2,2,3,3,2,5,5,6,6,7,7};
    int n = 13;

    int ansIndex = findOddOccuringElement(arr, n);
    cout<<"Odd occuring element is: "<<arr[ansIndex]<<endl;
}