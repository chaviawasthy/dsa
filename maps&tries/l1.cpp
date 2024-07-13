#include<bits/stdc++.h>

using namespace std;

int main(){

    //creation
    unordered_map<string, int>mapping;

    //insertion
    pair<string, int> p = make_pair("chavi", 3);
    pair<string, int> q("varnika", 20);
    pair<string, int> r;
    q.first = "mumma";
    q.second = 50;
    //insertion
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    //insert
    mapping["chavi"] = 61;

    cout<<"size of map: "<<mapping.size()<<endl;
    //access
    cout<<mapping.at("chavi")<<endl;
    cout<<mapping["varnika"]<<endl;

    //searching
    cout<<mapping.count("chavi")<<endl;

    if(mapping.find("chavi") == mapping.end()){
        cout<<"not found"<<endl;
    }else{
        cout<<"found"<<endl;
    }

    return 0;

}