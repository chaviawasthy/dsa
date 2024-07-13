#include<bits/stdc++.h>

using namespace std;

void print(vector<int>v){
    cout<<"Printing vector:"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" "; //or
        // cout<<v.at(i)<<" ";   both will give same output
    }
}

void print1(vector<int>v){
    cout<<"Printing vector:"<<endl;
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    print2(v);

    //vector initialisation
    vector<int>arr;
    vector<int>arr1(5,10); //5 elements with value 10
    print(arr1);
    vector<int>arr2(arr1); //copy of arr1
    vector<int>arr3{1,2,3,4,5}; //initialise with array
    print(arr3);
    arr3.pop_back();
    print(arr3);
    vector<int>arr4{1,2,3,4,5,6,7,8,9,10};
    print(arr4);


    vector<char>ch;
    ch.push_back('a');
    ch.push_back('b');
    ch.push_back('c');
    ch.push_back('d');
    cout<<"Printing char vector:"<<endl;
    for(int i=0; i<ch.size(); i++){
        cout<<ch[i]<<" ";
    }
    cout<<"Front element: "<<ch.front()<<endl;
    cout<<"Front element: "<<ch[0]<<endl;
    cout<<"Back element: "<<ch.back()<<endl;
    cout<<"End element: "<<ch.[ch.size()-1]<<endl; //or
    cout<<"End element: "<<ch.end()<<endl;

    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    print(v);
    //clear the vector
    v.clear();
    print(v);
    //we can increase the size of vector
    v.resize(10);
    print(v);
    //pop
    v.pop_back();
    print(v);
}