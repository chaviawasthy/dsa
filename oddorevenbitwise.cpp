// #include<iostream>

// using namespace std;

// bool checkEven(int n){
//     if (n%2==0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int main(){
//     int n;
//     cin>>n;

//     bool isEven = checkEven(n);

//     if (isEven)
//     {
//         cout<<n<<" is even"<<endl;
//     }
//     else{
//         cout<<n<<" is odd"<<endl;
//     }

//     return 0;
// }

//Bitwise Operator

#include<iostream>

using namespace std;

bool checkEven(int n){
    if ((n&1)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    int n;
    cin>>n;

    bool isEven = checkEven(n);

    if (isEven)
    {
        cout<<n<<" is even"<<endl;
    }
    else{
        cout<<n<<" is odd"<<endl;
    }
    return 0;
}