#include<bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int mid = (start+end)/2;
    while(start<=end){
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) end = mid-1;
        else start = mid+1;
        mid = (start+end)/2;
    }
    return -1;
}

int findFirstOccurence(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;    // to avoid overflow
    int ans = -1;

    while (s<=e)
    {
        if(arr[mid]==key){
            ans = mid;
            e = mid-1;
        }
        else if(arr[mid]>key) e = mid-1;
        else s = mid+1;
        mid = (s+e)/2;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) cin>>arr[i];
    int key;
    cin>>key;
    int ans = findFirstOccurence(arr,n,key);
    if(ans==-1) cout<<"Key not found";
    else cout<<"Key found at index "<<ans;

}