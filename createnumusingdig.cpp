#include<iostream>

using namespace std;

int createnumofdigits(int numofdigits){
    int num = 0;
    for(int i=0; i<numofdigits; i++){
        cout<<"Enter the digit: "<<endl;
        int digit;
        cin>>digit;
        num = num*10 + digit;
    }
    return num;
}

int main(){
    int numofdigits;
    cin>>numofdigits;
    int num = createnumofdigits(numofdigits);
    cout<<"Number created by digits: "<<num<<endl;
    return 0;
}