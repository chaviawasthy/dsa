#include<iostream>

using namespace std;

void printAllDigits(int n){
    while(n){
        int digit = n%10;
        cout<<"Digit: "<<digit<<endl;
        n = n/10;
    }
}

int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    printAllDigits(n);

}