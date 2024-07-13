#include<bits/stdc++.h>

using namespace std;

void getIthBit(int n, int i){
    int mask = (1<<i);
    int ans = n & mask;
    if (ans == 0)
    {
        cout<<"bit-> 0"<<endl;
    }
    else{
        cout<<"bit-> 1"<<endl;
    }
    
}

void setIthBit(int n, int i){
    int mask = (1<<i);
    int ans = n | mask;
    cout<<ans<<endl;
}

void clearIthBit(int n, int i){
    int mask = ~(1<<i);
    int ans = n & mask;
    cout<<ans<<endl;
}

void updateithBit(int n, int i, int v){ //v->target
    int mask = ~(1<<i);
    int cleared_n = n & mask;
    int ans = cleared_n | (v<<i);
    cout<<ans<<endl;
}

void clearLastiBits(int n, int i){
    int mask = (-1<<i);
    int ans = n & mask;
    cout<<ans<<endl;
}

bool checkPowerOf2(int n){
    //count set bit
    int count = 0;
    while (n!=0)
    {
        int lastbit = n & 1;
        if (lastbit)
        {
            count++;
        }
        n = n >> 1;
    }
    if (count == 1)
    {
        return true;
    }
    else{
        return false;
    }
    
}

bool fastCheckPowerOf2(int n){
    if (n & (n-1) == 0)
    {
        return true;
    }
    else{
        return false;
    }  
}

int fastCountSetBits(int n){
    int count = 0;
    while (n!=0)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

void clearBitsInRange(int n, int i, int j){
    int a = (-1<<(j+1));
    int b = (1<<i)-1;
    int mask = a|b;
    int ans = n & mask;
    cout<<ans<<endl;
}

void getSubsequences(string str) {
    int n = str.length();
    vector<string> ans;
    for (int num = 0; num < (1<<n); num++)
    {
        /* number is ready */
        //use number to create subsequences

        //num -> set bit ->index ->character ->include
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            //i->index
            char ch = str[i];
            //agar i index pr num k andar set bit present hai
            //toh character include kro
            if (num & (1<<i))
            {
                temp.push_back(ch);
            }
        }
        ans.push_back(temp);
    }
    cout<<"Printing the subsequences: "<<endl;
    for (auto s : ans)
    {
        cout<<s<<endl;
    }
    
}
    

int main(){
    int n = 16;
    int i = 2;
    // getIthBit(n,i);
    setIthBit(n,i);
    clearIthBit(n,i);
    updateithBit(n,i,1);
    clearLastiBits(n,i);
    cout<<checkPowerOf2(n)<<endl;
    cout<<fastCheckPowerOf2(n)<<endl;
    cout<<fastCountSetBits(n)<<endl;
    clearBitsInRange(n,2,3);
    string str = "abc";
    getSubsequences(str);

    return 0;
}