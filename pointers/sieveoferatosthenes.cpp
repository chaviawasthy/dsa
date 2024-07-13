// #include<bits/stdc++.h>

// using namespace std;

// vector<bool> sieve(int n){
//     vector<bool> sieve(n+1, true);
//     sieve[0] = sieve[1] = false;

//     for (int i = 2; i <= n; i++)
//     {
//         if (sieve[i]==true)
//         {
//             int j = i*2;
//             while(j<=n){
//                 sieve[j] = false;
//                 j += i;
//             }
//         }
        
//     }
//     return sieve;
// }

// int main(){
//     vector<bool> primes = sieve(25);
//     for (int i = 0; i <= 25; i++)
//     {
//         if (primes[i])
//         {
//             cout<<i<<" ";
//         }
        
//     }
//     return 0;
// }

//Optimised code
#include<bits/stdc++.h>

using namespace std;

vector<bool> sieve(int n){
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i*i <= n; i++)
    {
        if (sieve[i]==true)
        {
            int j = i*i;
            while(j<=n){
                sieve[j] = false;
                j += i;
            }
        }
        
    }
    return sieve;
}

int main(){
    vector<bool> primes = sieve(25);
    for (int i = 0; i <= 25; i++)
    {
        if (primes[i])
        {
            cout<<i<<" ";
        }
        
    }
    return 0;
}