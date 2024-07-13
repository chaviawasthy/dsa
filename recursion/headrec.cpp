#include<bits/stdc++.h>

using namespace std;

void printDigits(int num){
    //base case
    if(num==0) return;

    //processing
    int digit = num%10;
    num=num/10;

    //recursive call
    printDigits(num);

    //processing
    cout<<digit<<" ";
}

int main(){
     int num = 4315;
     printDigits(num);
}