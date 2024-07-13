#include<bits/stdc++.h>

using namespace std;

void findMin(int arr[], int size, int index, int &mini){
    //base case
    if(index>=size) return;

    //processing
    mini = min(mini, arr[index]);

    //recursive call
    findMin(arr, size, index+1, mini);

}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int index = 0;

    int mini = INT_MAX;
    findMin(arr, size, index, mini);
    cout<<"Minimum element: "<<mini<<endl;
    return 0;
}