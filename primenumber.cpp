// #include<iostream>
// #include<math.h>

// using namespace std;

// bool checkPrime(int n){
//     for (int i = 2; i <= sqrt(n); i++) //simply with n bhi ho sakta hai but sqrt(n) is more efficient because it will reduce the time complexity
//     {
//         if (n%i==0)
//         {
//             return false;
//         }
        
//     }
//     return true;
// }

// int main(){
//     int n;
//     cin>>n;

//     bool isPrime = checkPrime(n);
//     if (isPrime)
//     {
//         cout<<n<<" is prime"<<endl;
//     }
//     else{
//         cout<<n<<" is not prime"<<endl;
//     }

//     return 0;
// }

//Print all prime numbers from 1 to N

#include<iostream>

using namespace std;

bool checkPrime(int n){
    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
        
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    for (int i = 2; i <= n; i++)
    {
        bool isPrime = checkPrime(i);
        if (isPrime)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}