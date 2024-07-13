// #include<bits/stdc++.h>

// using namespace std;

// int sum(int n){
//     if(n==1) return 1;
//     int ans = n+sum(n-1);
//     return ans;
// }

// int main(){
//     cout<<sum(10)<<endl;
//     return 0;
// }

//sum og array
#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size, int index){
    //base case
    if(index==size) return;

    //processing
    cout<<arr[index]<<" ";

    //recursive call
    printArray(arr, size, index+1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    printArray(arr, 5, 0);
    return 0;
}