#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<int>> arr(5,vector<int>(10,0));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

    //jagged array
    vector<vector<int>> arr1;

    vector<int> v1(10,0);
    vector<int> v2(20,1);
    vector<int> v3(30,2);
    vector<int> v4(40,3);
    vector<int> v5(50,4);

    arr1.push_back(v1);
    arr1.push_back(v2);
    arr1.push_back(v3);
    arr1.push_back(v4);
    arr1.push_back(v5);

    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr1[i].size(); j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

}