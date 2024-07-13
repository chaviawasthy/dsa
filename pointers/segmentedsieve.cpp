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


vector<bool> segSieve(int L, int R){
    //get me prime array, i will use it to apply seg sieve
    vector<bool> sieve1 = sieve(sqrt(R));
    vector<int> basePrimes;
    for (int i = 0; i < sieve1.size(); i++)
    {
        if (sieve1[i])
        {
            basePrimes.push_back(i);
        }
        
    }
    vector<bool> segSieve(R-L+1, true);
    if (L==1 || L==0)
    {
        segSieve[L] = false;
    }
    for(auto prime: basePrimes){
        int first_multiple = (L/prime)*prime;
        if(first_multiple<L){
            first_multiple += prime;
        }
        int j = max(first_multiple, prime*prime);
        while(j<=R){
            segSieve[j-L] = false;
            j+=prime;
        }
    }
    return segSieve;
}

int main(){
    vector<bool> Sieve = segSieve(110, 130);
    for (int i = 0; i < Sieve.size(); i++)
    {
        if(Sieve[i]){
            cout<<i+110<<" ";}
    }
    
    return 0;
}