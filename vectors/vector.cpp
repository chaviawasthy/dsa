#include<bits/stdc++.h>

using namespace std;

void print(vector<int>v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    print(v);
    v.pop_back();
    print(v);
}