#include<bits/stdc++.h>

using namespace std;

void printSubarray1(vector<int>&nums,int start, int end){
    //base case
    if(end==nums.size()){
        return;
    }

    //one case
    for(int i=start;i<=end;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    //recursive case
    printSubarray1(nums,start,end+1);
}

void printSubarray(vector<int>&nums){
    for(int start=0;start<nums.size();start++){
        int end = start;
        printSubarray1(nums,start,end);
    }
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    printSubarray(nums);

    return 0;
}

//TC->O(N^2)
//SC->O(N) -> stack space