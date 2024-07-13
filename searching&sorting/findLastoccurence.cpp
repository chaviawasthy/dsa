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

int lastOccurence(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans = -1;

    while (s<=e)
    {
        if(arr[mid]==target){
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid]<target) s = mid+1;
        else if(target<arr[mid]) e = mid-1;
        mid = s+(e-s)/2;
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
    int ans = lastOccurence(arr,n,key);
    if(ans==-1) cout<<"Key not found";
    else cout<<"Key found at index "<<ans;

}