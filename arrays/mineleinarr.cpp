#include<iostream>
#include<limits.h>

using namespace std;

void minele(int arr[], int n){
    int min = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    cout<<min;
}

int main(){
    int arr[] = {100,2,5,88,96,5,22,33,74,84};
    minele(arr, 10);
    return 0;

}

//or

#include<iostream>
#include<limits.h>

using namespace std;

int main(){
    int arr[] = {100,2,5,88,96,5,22,33,74,84};
    int min = INT_MAX;
    for(int i=0; i<10; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    cout<<min;
    return 0;
}