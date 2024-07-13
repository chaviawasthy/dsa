#include<bits/stdc++.h>

using namespace std;

bool checkSorted(int arr[], int size, int index){
    //base case
    if (index>=size)
    {
        return true;
    }

    //processing
    if (arr[index] > arr[index-1])
    {
     //aage check karna padega ab and then recursion sambhal lega
     bool aageAns = checkSorted(arr, size, index+1);
     return aageAns;
    }
    else{
        return false;
    }
}

int main(){
    int arr[] = {10,20,30,50,60,70};
    int size = 6;
    int index = 1;

    bool isSorted = checkSorted(arr, size, index);

    if (isSorted)
    {
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    
}