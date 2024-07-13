#include<iostream>

using namespace std;

int incrementBy(int n){
    n++;
    return n;
}

int main(){
    int n;
    cin>>n;
    cout<<incrementBy(n)<<endl;
    return 0;
}

//call by reference

#include<iostream>

using namespace std;

void incrementBy(int &k){
    k++;
}

int main(){
    int n;
    cin>>n;
    incrementBy(n);
    cout<<n<<endl;
    return 0;
}