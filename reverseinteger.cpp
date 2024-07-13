// #include<iostream>

// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int reverse = 0;             // this code doesn't take care of the negative numbers
//     while (n>0)
//     {
//         int lastdigit = n%10;
//         reverse = reverse*10 + lastdigit;
//         n = n/10;
//     }
//     cout<<reverse<<endl;
    
//     return 0;
// }

#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int ans = 0, rem = 0;
    bool isneg = false;
    if(n<=INT32_MIN){
        return 0;
    }
    if(n<0){
        isneg = true;
        n = -n;
    }
    while (n>0)
    {
        if(ans > INT32_MAX/10){
            return 0;
        }
        rem = n%10;
        ans = ans*10 + rem;
        n = n/10;
    }
    return isneg ? -ans : ans;
}