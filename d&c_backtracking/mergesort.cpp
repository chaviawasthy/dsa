#include<bits/stdc++.h>

using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int lenLeft = mid-s+1;
    int lenRight = e-mid;

    //create left and right array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    //copy values from original array to left array
    int k = s;
    //k-> starting index of left array values in original array
    for (int i = 0; i < lenLeft; i++)
    {
        left[i] = arr[k];
        k++;
    }
    
    //copy values from original array to right array
    k = mid+1;
    //k-> starting index of right array values in original array
    for (int i = 0; i < lenRight; i++)
    {
        right[i] = arr[k];
        k++;
    }

    //actual merging
    //left array->already sorted
    //right array->already sorted

    int leftIndex = 0;
    int rightIndex = 0;
    //yahi par galti karte hai log
    int mainArrayIndex = s;

    while(leftIndex<lenLeft && rightIndex<lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    //2 more cases
    //1case->left array exhaust but right array me element abhi bhi bache hai
    //1case->right array exhaust but left array me element abhi bhi bache hai
    while(rightIndex<lenRight){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    while(leftIndex<lenLeft){
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    //delete the dynamically allocated memory ->important
    delete [] left;
    delete [] right;

}

void mergeSort(int arr[], int s, int e){
    //base case
    if (s>e)
    {
        return;  //invalid array
    }
    if(s==e){
        return;  //single element array
    }
    
    //break the array into two parts
    int mid = (s+e)/2;
    //s->mid->left
    //mid+1->e->right

    //sort the left and right array using recursion
    mergeSort(arr,s,mid); //left array
    mergeSort(arr,mid+1,e); //right array

    //merge the sorted arrays
    merge(arr,s,e);
}

int main(){
    int arr[] = {2,1,6,9,4,5};
    int size = 6;
    int s = 0;
    int e = size-1;

    cout<<"Before merge sort: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergeSort(arr, s, e);
    cout<<"After merge sort: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}