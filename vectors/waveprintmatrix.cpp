#include<bits/stdc++.h>

using namespace std;

void wavePrint(vector<vector<int>>arr){
    int n = arr.size();
    int m = arr[0].size();
    for (int startCol = 0; startCol < n; startCol++)
    {
        //even number of col-> top to bottom
        if(startCol%2==0){           //or if(startCol&1==0)
            for (int i = 0; i < m; i++)
            {
                cout<<arr[i][startCol]<<" ";
            }
            
        }

        //odd number of col-> bottom to top
        else{
            for (int i = m-1; i >= 0; i--)
            {
                cout<<arr[i][startCol]<<" ";
            }
            
        }

    }
    
}

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    wavePrint(arr);
    return 0;
}