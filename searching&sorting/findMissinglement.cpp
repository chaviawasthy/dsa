#include<bits/stdc++.h>

using namespace std;

int findMissingElement(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;    // to avoid overflow
    int ans = -1;

    while (s<=e)
    {
        int diff = arr[mid] - mid;
        if (diff == 1)
        {
            s = mid+1;
        }
        else{
            ans = mid;
            e = mid-1;
        }
        mid = s + (e-s)/2;
        
    }

    if (ans + 1 == 0)  // if the missing element is the last element of the array
    {
        return n+1;
    }
    
    return ans+1;
}

int main(){
    int arr[] = {1,2,3,4,6,7,8,9};
    int n = 8;
    cout<<"Missing Element is: "<<findMissingElement(arr,n);

    return 0;
}